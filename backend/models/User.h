#pragma once
#include <string>

class User {
private:
    int id;
    std::string username;
    std::string passwordHash; // stored hash of password
    std::string role; // TA, Instructor, AcademicOfficer, HOD, etc.
public:
    User() = default;
    User(int id, const std::string &username, const std::string &passwordHash, const std::string &role)
        : id(id), username(username), passwordHash(passwordHash), role(role) {}

    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getPasswordHash() const { return passwordHash; }
    std::string getRole() const { return role; }

    void setId(int i) { id = i; }
    void setUsername(const std::string &u) { username = u; }
    void setPasswordHash(const std::string &h) { passwordHash = h; }
    void setRole(const std::string &r) { role = r; }
};
