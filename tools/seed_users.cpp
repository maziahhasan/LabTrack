#include <iostream>
#include <vector>
#include "../backend/repositories/UserRepository.h"

int main() {
    UserRepository repo("users.bin");
    std::vector<User> users;
    users.emplace_back(1, "admin", "adminpass", "AcademicOfficer", "admin@uni.edu");
    users.emplace_back(2, "ta1", "ta_pass", "TA", "ta1@uni.edu");
    users.emplace_back(3, "instr1", "instr_pass", "Instructor", "instr1@uni.edu");
    users.emplace_back(4, "hod1", "hod_pass", "HOD", "hod1@uni.edu");
    users.emplace_back(5, "att1", "att_pass", "Attendant", "att1@uni.edu");
    repo.saveAll(users);
    std::cout << "Seeded users.bin with " << users.size() << " users.\n";
    return 0;
}
