#pragma once
#include <vector>
#include <fstream>
#include "../models/Instructor.h"

class InstructorRepository {
private:
    std::string fileName;
public:
    InstructorRepository(const std::string &file = "instructors.bin");
    void save(const std::vector<Instructor>& v);
    std::vector<Instructor> load();
    int getNextId();
    void add(const Instructor &ins);
    std::vector<Instructor> getAll();
    // convenience lookup; returns heap-allocated pointer or nullptr
    Instructor* getInstructorById(int id) {
        auto v = load();
        for (const auto &i : v) if (i.getId() == id) return new Instructor(i);
        return nullptr;
    }
    // Add this method:
bool update(const Instructor& ins);

};
