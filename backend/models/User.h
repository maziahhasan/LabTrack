#pragma once
#include <string>

class User {
private:
    int id = -1;                    // User ID
    std::string username;           // Username (unique)
    std::string password;           // Stored password (plaintext) -- insecure
    std::string role;               // TA, Instructor, AcademicOfficer, HOD, etc.
    std::string email;              // Email address
    std::string status = "Active"; // Status (Active/Inactive)

public:
    User() = default;
    User(int id, const std::string &username, const std::string &password, const std::string &role, const std::string& email = "")
        : id(id), username(username), password(password), role(role), email(email) {}

    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getRole() const { return role; }
    std::string getEmail() const { return email; }
    std::string getStatus() const { return status; }

    void setId(int i) { id = i; }
    void setUsername(const std::string &u) { username = u; }
    void setPassword(const std::string &p) { password = p; }
    void setRole(const std::string &r) { role = r; }
    void setEmail(const std::string& e) { email = e; }
    void setStatus(const std::string& s) { status = s; }
};
