#pragma once
#include <vector>
#include <string>
#include "../models/AcademicOfficer.h"

class AcademicOfficerRepository {
private:
    std::string fileName;
public:
    AcademicOfficerRepository(const std::string &file = "academic_officers.bin");
    void save(const std::vector<AcademicOfficer> &v);
    std::vector<AcademicOfficer> load();
    int getNextId();
    void add(const AcademicOfficer &a);
    std::vector<AcademicOfficer> getAll();
};
