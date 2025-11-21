#pragma once
#include <string>

class HOD {
private:
    int id;
    std::string name;
    std::string department;
public:
    HOD() = default;
    HOD(int id, const std::string &name, const std::string &dept = "") : id(id), name(name), department(dept) {}
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getDepartment() const { return department; }
};
