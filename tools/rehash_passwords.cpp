// Tool to rehash existing passwords in users.txt
// Run this once after implementing password hashing
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <functional>
#include "../backend/repositories/UserRepository.h"
#include "../backend/services/AuthService.h"

int main() {
    UserRepository userRepo("users.txt");
    
    auto users = userRepo.loadAll();
    std::cout << "Found " << users.size() << " users\n";
    
    // For each user, rehash their password (assuming they're currently plaintext)
    std::vector<User> updatedUsers;
    for (auto& user : users) {
        std::string currentPassword = user.getPassword();
        
        // Check if already hashed (hashed passwords are hex strings, typically 16 chars)
        // If it looks like plaintext (contains non-hex or is short), rehash it
        bool needsRehash = false;
        if (currentPassword.length() < 10) {
            needsRehash = true;
        } else {
            // Check if contains non-hex characters
            for (char c : currentPassword) {
                if (!std::isxdigit(c)) {
                    needsRehash = true;
                    break;
                }
            }
        }
        
        if (needsRehash) {
            std::string hashedPassword = AuthService::computeHash(currentPassword);
            std::cout << "Rehashing user: " << user.getUsername() 
                     << " (old: " << currentPassword << " -> new: " << hashedPassword << ")\n";
            user.setPassword(hashedPassword);
        } else {
            std::cout << "User " << user.getUsername() << " already has hashed password\n";
        }
        
        updatedUsers.push_back(user);
    }
    
    // Save updated users
    userRepo.saveAll(updatedUsers);
    std::cout << "\nPassword rehashing complete!\n";
    std::cout << "All users now have hashed passwords.\n";
    
    return 0;
}
