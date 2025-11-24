#include <iostream>
#include <functional>
#include <sstream>
#include "../backend/repositories/UserRepository.h"
#include "../backend/models/User.h"

static std::string hashPw(const std::string &pw) {
    // store plaintext (insecure) — function kept for minimal changes
    return pw;
}

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Usage: add_user <username> <password> <role> [email]\n";
        return 1;
    }
    std::string username = argv[1];
    std::string password = argv[2];
    std::string role = argv[3];
    std::string email = argc >= 5 ? argv[4] : "";

    UserRepository repo("users.bin");
    int id = repo.getNextId();
    User u(id, username, hashPw(password), role, email);
    repo.add(u);
    std::cout << "Added user: " << username << " id=" << id << " role=" << role << "\n";
    return 0;
}
