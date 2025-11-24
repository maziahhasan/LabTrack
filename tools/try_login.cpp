#include <iostream>
#include "../backend/repositories/UserRepository.h"
#include "../backend/services/AuthService.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "Usage: try_login <username_or_email> <password>\n";
        return 1;
    }
    std::string user = argv[1];
    std::string pw = argv[2];

    UserRepository repo("users.bin");
    AuthService auth(repo);

    User found = repo.findByUsername(user);
    if (found.getUsername().empty()) {
        std::cout << "User not found for key: " << user << "\n";
    } else {
        std::cout << "Found user: id=" << found.getId() << " username=" << found.getUsername() << " email=" << found.getEmail() << " role=" << found.getRole() << " storedPassword=" << found.getPassword() << "\n";
    }

    User out;
    bool ok = auth.authenticate(user, pw, out);
    std::cout << "Auth result: " << (ok ? "SUCCESS" : "FAILURE") << "\n";
    if (ok) {
        std::cout << "Authenticated user: id=" << out.getId() << " username=" << out.getUsername() << " role=" << out.getRole() << "\n";
    }
    return 0;
}
