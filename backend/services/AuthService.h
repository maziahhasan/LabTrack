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
    AuthService(UserRepository &repo, InstructorRepository *irepo = nullptr, TARepository *trepo = nullptr, HODRepository *hrepo = nullptr, AcademicOfficerRepository *aorepo = nullptr, BuildingRepository *brepo = nullptr);
    bool assignAttendantToBuilding(int userId, int buildingId);
    bool registerUser(const std::string &username, const std::string &password, const std::string &role);
    bool authenticate(const std::string &username, const std::string &password, User &outUser);
};
