#include <iostream>
#include <string>
#include <sstream>
#include <functional>

std::string hashPassword(const std::string &pw) {
    std::hash<std::string> hasher;
    size_t hash = hasher(pw + "labtrack_salt_2025");
    std::ostringstream oss;
    oss << hash;
    return oss.str();
}

int main() {
    std::cout << "admin|adminpass|" << hashPassword("adminpass") << "\n";
    std::cout << "instr_a|instrpass|" << hashPassword("instrpass") << "\n";
    std::cout << "hod_a|hodpass|" << hashPassword("hodpass") << "\n";
    std::cout << "ta_a|tapass|" << hashPassword("tapass") << "\n";
    std::cout << "att_a|attpass|" << hashPassword("attpass") << "\n";
    return 0;
}
