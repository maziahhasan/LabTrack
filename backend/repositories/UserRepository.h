#pragma once
#include <vector>
#include <string>
#include "../models/User.h"

class UserRepository {
private:
    std::string fileName; // binary file storing users
public:
    UserRepository(const std::string &file = "users.bin");
    std::vector<User> loadAll();
    void saveAll(const std::vector<User> &users);
    void add(const User &u);
    bool update(const User &u);
    int getNextId();
    User findByUsername(const std::string &username);
    // New queries for new model fields
    std::vector<User> getUsersByRole(const std::string& role);
    std::vector<User> getUsersByStatus(const std::string& status);
    std::vector<User> getUsersByEmail(const std::string& email);
};
