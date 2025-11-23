#include "UserRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

// Helper function to trim whitespace from both ends of a string
static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

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
        if (!std::getline(ss, role, '|')) {
            // If no pipe found, read rest of line (might have newline)
            role = "";
            std::getline(ss, role);
        }
        // Trim all fields to remove any whitespace issues
        idS = trim(idS);
        user = trim(user);
        hash = trim(hash);
        role = trim(role);
        if (idS.empty() || user.empty() || hash.empty()) continue;
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
    // Case-insensitive lookup: normalize to lowercase for comparison
    std::string lookup = username;
    std::transform(lookup.begin(), lookup.end(), lookup.begin(), [](unsigned char c){ return std::tolower(c); });
    for (const auto &u : v) {
        std::string stored = u.getUsername();
        std::transform(stored.begin(), stored.end(), stored.begin(), [](unsigned char c){ return std::tolower(c); });
        if (stored == lookup) return u;
    }
    return User();
}
