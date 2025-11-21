#include <iostream>
#include "../repositories/UserRepository.h"
#include "../services/AuthService.h"

int main() {
    UserRepository ur("users.txt");
    InstructorRepository ir("instructors.bin");
    TARepository tr("tas.bin");
    HODRepository hr("hods.bin");
    AcademicOfficerRepository ar("academic_officers.bin");
    AuthService auth(ur, &ir, &tr, &hr, &ar);

    // register a few users; TA and Instructor entries will be created automatically
    auth.registerUser("alice", "password123", "TA");
    auth.registerUser("bob", "secret", "Instructor");
    auth.registerUser("officer", "adminpass", "AcademicOfficer");

    User u;
    if (auth.authenticate("alice", "password123", u)) std::cout << "alice logged in as " << u.getRole() << "\n";
    else std::cout << "alice failed login\n";

    if (auth.authenticate("bob", "wrong", u)) std::cout << "bob logged in\n";
    else std::cout << "bob failed login as expected\n";

    return 0;
}
