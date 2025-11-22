#pragma once
#include <vector>
#include <fstream>
#include "../models/Lab.h"
using namespace std;

using namespace std;

class LabRepository {
private:
    string fileName;

    void writeString(ofstream &out, const string &s);
    string readString(ifstream &in);

public:
    LabRepository(const string &file = "labs.bin");

    void saveLabs(const vector<Lab> &labs);
        vector<Lab> loadLabs();

    // Convenience CRUD operations built on top of save/load
    Lab getById(int id);
    // compatibility: simple getter name used by some services
    std::vector<Lab> getAll() { return loadLabs(); }
    // backward-compatible names used by UI
    vector<Lab> getAllLabs() { return loadLabs(); }
    // return heap-allocated Lab pointer or nullptr (caller not owned by repo)
    Lab* getLabById(int id) {
        auto v = loadLabs();
        for (const auto &l : v) if (l.getId() == id) return new Lab(l);
        return nullptr;
    }
    void add(const Lab &lab);
    bool update(const Lab &lab);
    bool remove(int id);
    int getNextId();
    std::vector<Lab> getLabsByInstructorId(int instructorId);

};
