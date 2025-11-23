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
    bool update(const Instructor& ins);
    std::vector<Instructor> getAll();
    // New queries for new model fields
    std::vector<Instructor> getInstructorsByStatus(const std::string& status);
    std::vector<Instructor> getInstructorsByEmail(const std::string& email);
    // Return pointer (caller may assume ownership) to match UI usage patterns
    Instructor* getInstructorById(int id) {
        auto v = load();
        for (const auto &i : v) if (i.getId() == id) return new Instructor(i);
        return nullptr;
    }
};
