#pragma once
#include <string>

class AcademicOfficer {
private:
    int id;
    std::string name;
public:
    AcademicOfficer() = default;
    AcademicOfficer(int id, const std::string &name) : id(id), name(name) {}
    int getId() const { return id; }
    std::string getName() const { return name; }
};
