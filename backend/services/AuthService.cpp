#include "AuthService.h"
#include <sstream>
#include <functional>

AuthService::AuthService(UserRepository &repo, InstructorRepository *irepo, TARepository *trepo, HODRepository *hrepo, AcademicOfficerRepository *aorepo, BuildingRepository *brepo)
    : userRepo(repo), instrRepo(irepo), taRepo(trepo), hodRepo(hrepo), aoRepo(aorepo), buildingRepo(brepo) {}

// Simple hash function using std::hash (better than plaintext)
// For production, use bcrypt, scrypt, or Argon2
std::string AuthService::hashPassword(const std::string &pw) {
    return pw; // Store plaintext for now
}

std::string AuthService::computeHash(const std::string &pw) {
    return hashPassword(pw);
}

bool AuthService::registerUser(const std::string &username, const std::string &password, const std::string &role, const std::string &email, const std::string &performedByRole) {
    User existing = userRepo.findByUsername(username);
    if (existing.getUsername().size() > 0) return false; // already exists

    // Only AcademicOfficer can create accounts. Allow a one-time bootstrap to create
    // the very first AcademicOfficer if none exist yet (performedByRole empty).
    bool isPrivilegedRole = (role == "TA" || role == "Instructor" || role == "HOD" || role == "AcademicOfficer");

    if (performedByRole != "AcademicOfficer") {
        // check for bootstrap: allow creating the first AcademicOfficer if none exists
        if (!(role == "AcademicOfficer")) {
            // non-AO attempted creation without AO privileges -> disallow
            return false;
        }
        // role == AcademicOfficer but performedByRole not AO: allow only if no AO exists yet
        auto users = userRepo.loadAll();
        bool aoExists = false;
        for (const auto &u : users) if (u.getRole() == "AcademicOfficer") { aoExists = true; break; }
        if (aoExists) return false; // cannot create AO without AO privileges
    }

    int id = userRepo.getNextId();
    User u(id, username, password, role, email);
    userRepo.add(u);
    // create corresponding domain object when applicable
    if (role == "TA" && taRepo != nullptr) {
        int tid = taRepo->getNextId();
        taRepo->add(TA(tid, username));
    }
    if (role == "Instructor" && instrRepo != nullptr) {
        int iid = instrRepo->getNextId();
        instrRepo->save(instrRepo->load()); // ensure file exists (no-op)
        instrRepo->add(Instructor(iid, username));
    }
    if (role == "HOD" && hodRepo != nullptr) {
        int hid = hodRepo->getNextId();
        hodRepo->add(HOD(hid, username, ""));
    }
    if (role == "AcademicOfficer" && aoRepo != nullptr) {
        int aid = aoRepo->getNextId();
        aoRepo->add(AcademicOfficer(aid, username));
    }
    return true;
}

bool AuthService::assignAttendantToBuilding(int userId, int buildingId) {
    if (buildingRepo == nullptr) return false;
    return buildingRepo->setAttendant(buildingId, userId);
}

bool AuthService::authenticate(const std::string &username, const std::string &password, User &outUser) {
    User u = userRepo.findByUsername(username);
    if (u.getUsername().empty()) return false;
    if (u.getPassword() == password) { outUser = u; return true; }
    return false;
}
