#include "UserRepository.h"
#include <fstream>
#include <algorithm>

static void writeString(std::ofstream &out, const std::string &s) {
    int len = (int)s.size();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len);
}

static std::string readString(std::ifstream &in) {
    int len = 0;
    in.read((char*)&len, sizeof(len));
    if (!in || len < 0) return std::string();
    char *buf = new char[len+1];
    in.read(buf, len);
    buf[len] = '\0';
    std::string s(buf);
    delete[] buf;
    return s;
}

UserRepository::UserRepository(const std::string &file) : fileName(file) {}

std::vector<User> UserRepository::loadAll() {
    std::vector<User> out;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return out;
    int count = 0; in.read((char*)&count, sizeof(count));
    if (!in) return out;
    for (int i = 0; i < count; ++i) {
        int id = -1; in.read((char*)&id, sizeof(id));
        std::string user = readString(in);
        std::string pw = readString(in);
        std::string role = readString(in);
        std::string email = readString(in);
        std::string status = readString(in);
        out.emplace_back(id, user, pw, role, email);
        out.back().setStatus(status);
    }
    return out;
}

void UserRepository::saveAll(const std::vector<User> &users) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int count = (int)users.size(); out.write((char*)&count, sizeof(count));
    for (const auto &u : users) {
        int id = u.getId(); out.write((char*)&id, sizeof(id));
        writeString(out, u.getUsername());
        writeString(out, u.getPassword());
        writeString(out, u.getRole());
        writeString(out, u.getEmail());
        writeString(out, u.getStatus());
    }
}

void UserRepository::add(const User &u) {
    auto v = loadAll();
    v.push_back(u);
    saveAll(v);
}

bool UserRepository::update(const User &u) {
    auto v = loadAll();
    bool found = false;
    for (auto &it : v) {
        if (it.getId() == u.getId()) { it = u; found = true; break; }
    }
    if (found) saveAll(v);
    return found;
}

int UserRepository::getNextId() {
    auto v = loadAll(); int maxId = 0; for (const auto &u : v) if (u.getId() > maxId) maxId = u.getId(); return maxId + 1;
}

User UserRepository::findByUsername(const std::string &username) {
    auto v = loadAll();
    std::string lookup = username; std::transform(lookup.begin(), lookup.end(), lookup.begin(), [](unsigned char c){ return std::tolower(c); });
    for (const auto &u : v) {
        // check username
        std::string stored = u.getUsername(); std::transform(stored.begin(), stored.end(), stored.begin(), [](unsigned char c){ return std::tolower(c); });
        if (stored == lookup) return u;
        // check email as alternative login identifier
        std::string em = u.getEmail(); std::transform(em.begin(), em.end(), em.begin(), [](unsigned char c){ return std::tolower(c); });
        if (em == lookup) return u;
    }
    return User();
}

std::vector<User> UserRepository::getUsersByRole(const std::string &role) {
    auto v = loadAll(); std::vector<User> res; for (const auto &u : v) if (u.getRole() == role) res.push_back(u); return res;
}

std::vector<User> UserRepository::getUsersByStatus(const std::string &status) {
    auto v = loadAll(); std::vector<User> res; for (const auto &u : v) if (u.getStatus() == status) res.push_back(u); return res;
}

std::vector<User> UserRepository::getUsersByEmail(const std::string &email) {
    auto v = loadAll(); std::vector<User> res; for (const auto &u : v) if (u.getEmail() == email) res.push_back(u); return res;
}
#include "UserRepository.h"
