#pragma once
#include <string>

class TA {
private:
    int id;
    std::string name;

public:
    TA() = default;
    TA(int id, const std::string& name) : id(id), name(name) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
};
