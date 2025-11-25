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
    bool update(const Building &b);
    std::vector<Building> getAll();
    Building* getBuildingById(int id);
    bool setAttendant(int buildingId, int userId);
    // New queries for new model fields
    std::vector<Building> getBuildingsByAttendantId(int userId);
    std::vector<Building> getBuildingsByLocation(const std::string& location);
};
