#pragma once
#include <string>

class TA {
private:
    int id = -1;              // TA ID
    std::string name;         // TA name
    std::string email;        // TA email
    std::string status = "Active"; // Status (Active/Inactive)

public:
    TA() = default;
    TA(int id, const std::string& name, const std::string& email = "") : id(id), name(name), email(email) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getStatus() const { return status; }

    void setEmail(const std::string& e) { email = e; }
    void setStatus(const std::string& s) { status = s; }
};
