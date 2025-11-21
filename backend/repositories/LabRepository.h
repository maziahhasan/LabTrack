#pragma once
#include <vector>
#include <fstream>
#include "../models/Lab.h"

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
    vector<Lab> getAll();
    Lab getById(int id);
    void add(const Lab &lab);
    bool update(const Lab &lab);
    bool remove(int id);
    int getNextId();
};
