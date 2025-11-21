#pragma once
#include <vector>
#include <fstream>
#include "../models/Building.h"

class BuildingRepository {
private:
    std::string fileName;
public:
    BuildingRepository(const std::string &file = "buildings.bin");
    void save(const std::vector<Building>& v);
    std::vector<Building> load();
    int getNextId();
    void add(const Building &b);
    std::vector<Building> getAll();
};
