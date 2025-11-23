#pragma once
#include <string>

class Instructor {
private:
    int id = -1;              // Instructor ID
    std::string name;         // Instructor name
    std::string email;        // Instructor email
    std::string status = "Active"; // Status (Active/Inactive)

public:
    Instructor() = default;
    Instructor(int id, const std::string& name, const std::string& email = "") : id(id), name(name), email(email) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getStatus() const { return status; }

    void setId(int i) { id = i; }
    void setName(const std::string& n) { name = n; }
    void setEmail(const std::string& e) { email = e; }
    void setStatus(const std::string& s) { status = s; }
};
