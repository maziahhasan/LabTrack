#pragma once
#include "../repositories/UserRepository.h"
#include "../repositories/InstructorRepository.h"
#include "../repositories/TARepository.h"
#include "../repositories/HODRepository.h"
#include "../repositories/AcademicOfficerRepository.h"
#include "../repositories/BuildingRepository.h"
#include <string>

class AuthService {
private:
    UserRepository &userRepo;
    InstructorRepository *instrRepo;
    TARepository *taRepo;
    HODRepository *hodRepo;
    AcademicOfficerRepository *aoRepo;
    BuildingRepository *buildingRepo;
    // simple hashing placeholder (not cryptographically secure)
    static std::string hashPassword(const std::string &pw);
public:
    // Expose a public helper to compute hash (useful for debugging/password resets)
    static std::string computeHash(const std::string &pw);
    AuthService(UserRepository &repo, InstructorRepository *irepo = nullptr, TARepository *trepo = nullptr, HODRepository *hrepo = nullptr, AcademicOfficerRepository *aorepo = nullptr, BuildingRepository *brepo = nullptr);

    // Assign a user as building attendant
    bool assignAttendantToBuilding(int userId, int buildingId);

    // Register a new user. Only an AcademicOfficer may create accounts (performedByRole="AcademicOfficer").
    // A one-time bootstrap is allowed to create the very first AcademicOfficer if none exist yet (performedByRole empty).
    bool registerUser(const std::string &username, const std::string &password, const std::string &role, const std::string &email = "", const std::string &performedByRole = "");

    // Update user status (Active/Inactive)
    bool updateUserStatus(int userId, const std::string& status);
    // Update user email
    bool updateUserEmail(int userId, const std::string& email);
    // Update user role (by AO only)
    bool updateUserRole(int userId, const std::string& newRole, const User& actor);

    // Authenticate user
    bool authenticate(const std::string &username, const std::string &password, User &outUser);
};
