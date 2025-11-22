#pragma once
#include <string>

class Instructor {
private:
    int id = -1;
    std::string name;
    std::string email;

public:
    Instructor() = default;
    Instructor(int id, const std::string& name) : id(id), name(name) {}

    int getId() const { return id; }
    std::string getName() const { return name; }

    void setId(int i) { id = i; }
    void setName(const std::string& n) { name = n; }

    void setEmail(const std::string& e) { email = e; }
    std::string getEmail() const { return email; }
};
