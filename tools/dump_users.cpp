#include <iostream>
#include "../backend/repositories/UserRepository.h"

int main() {
    UserRepository repo("users.bin");
    auto users = repo.loadAll();
    if (users.empty()) {
        std::cout << "No users found in users.bin\n";
        return 0;
    }
    std::cout << "Users in users.bin:\n";
    for (const auto &u : users) {
        std::cout << "ID:" << u.getId() << " Username:" << u.getUsername()
                  << " Role:" << u.getRole() << " Email:" << u.getEmail()
                  << " Status:" << u.getStatus() << " Password:" << u.getPassword() << "\n";
    }
    return 0;
}
