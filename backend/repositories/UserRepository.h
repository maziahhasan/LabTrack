#pragma once
#include <vector>
#include <string>
#include "../models/User.h"

class UserRepository {
private:
    std::string fileName; // text file storing users: id|username|passwordHash|role
public:
    UserRepository(const std::string &file = "users.txt");
    std::vector<User> loadAll();
    void saveAll(const std::vector<User> &users);
    void add(const User &u);
    int getNextId();
    User findByUsername(const std::string &username);
};
