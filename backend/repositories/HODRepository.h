#pragma once
#include <vector>
#include <string>
#include "../models/HOD.h"

class HODRepository {
private:
    std::string fileName;
public:
    HODRepository(const std::string &file = "hods.bin");
    void save(const std::vector<HOD> &v);
    std::vector<HOD> load();
    int getNextId();
    void add(const HOD &h);
    std::vector<HOD> getAll();
};
