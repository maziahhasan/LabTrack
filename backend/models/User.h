#pragma once
#include <string>

class User {
private:
    int id = -1;                    // User ID
    std::string username;           // Username (unique)
    std::string passwordHash;       // Stored hash of password
    std::string role;               // TA, Instructor, AcademicOfficer, HOD, etc.
    std::string email;              // Email address
    std::string status = "Active"; // Status (Active/Inactive)

public:
    User() = default;
    User(int id, const std::string &username, const std::string &passwordHash, const std::string &role, const std::string& email = "")
        : id(id), username(username), passwordHash(passwordHash), role(role), email(email) {}

    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getPasswordHash() const { return passwordHash; }
    std::string getRole() const { return role; }
    std::string getEmail() const { return email; }
    std::string getStatus() const { return status; }

    void setId(int i) { id = i; }
    void setUsername(const std::string &u) { username = u; }
    void setPasswordHash(const std::string &h) { passwordHash = h; }
    void setRole(const std::string &r) { role = r; }
    void setEmail(const std::string& e) { email = e; }
    void setStatus(const std::string& s) { status = s; }
};
