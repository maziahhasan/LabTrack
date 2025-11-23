#pragma once
#include <vector>
#include <fstream>
#include "../models/Lab.h"
using namespace std;

using namespace std;

class LabRepository {
private:
    std::string fileName;

    void writeString(std::ofstream &out, const std::string &s);
    std::string readString(std::ifstream &in);

public:
    LabRepository(const std::string &file = "labs.bin");

    void saveLabs(const std::vector<Lab> &labs);
    std::vector<Lab> loadLabs();

    // CRUD operations
    Lab getById(int id);
    std::vector<Lab> getAll() { return loadLabs(); }
    std::vector<Lab> getAllLabs() { return loadLabs(); }
    Lab* getLabById(int id) {
        auto v = loadLabs();
        for (const auto &l : v) if (l.getId() == id) return new Lab(l);
        return nullptr;
    }
    void add(const Lab &lab);
    bool update(const Lab &lab);
    bool remove(int id);
    int getNextId();

    // New/updated queries for new model fields
    std::vector<Lab> getLabsByInstructorId(int instructorId);
    std::vector<Lab> getLabsByBuildingId(int buildingId);
    std::vector<Lab> getLabsByRoomId(int roomId);
    std::vector<Lab> getLabsByTAId(int taId);
    std::vector<Lab> getLabsByStatus(const std::string& status);

    // Update lab status
    bool updateStatus(int labId, const std::string& status);
    // Assign TAs
    bool setTAs(int labId, const std::vector<int>& taIds);
};
