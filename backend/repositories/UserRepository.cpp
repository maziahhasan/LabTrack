#include "UserRepository.h"
#include <fstream>
#include <sstream>

UserRepository::UserRepository(const std::string &file) : fileName(file) {}

std::vector<User> UserRepository::loadAll() {
    std::vector<User> out;
    std::ifstream in(fileName);
    if (!in.is_open()) return out;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string idS, user, hash, role;
        if (!std::getline(ss, idS, '|')) continue;
        if (!std::getline(ss, user, '|')) continue;
        if (!std::getline(ss, hash, '|')) continue;
        if (!std::getline(ss, role, '|')) role = "";
        int id = std::stoi(idS);
        out.push_back(User(id, user, hash, role));
    }
    return out;
}

void UserRepository::saveAll(const std::vector<User> &users) {
    std::ofstream out(fileName, std::ios::trunc);
    for (const auto &u : users) {
        out << u.getId() << "|" << u.getUsername() << "|" << u.getPasswordHash() << "|" << u.getRole() << "\n";
    }
}

void UserRepository::add(const User &u) {
    auto v = loadAll();
    v.push_back(u);
    saveAll(v);
}

int UserRepository::getNextId() {
    auto v = loadAll();
    int maxId = 0;
    for (const auto &u : v) if (u.getId() > maxId) maxId = u.getId();
    return maxId + 1;
}

User UserRepository::findByUsername(const std::string &username) {
    auto v = loadAll();
    for (const auto &u : v) if (u.getUsername() == username) return u;
    return User();
}
