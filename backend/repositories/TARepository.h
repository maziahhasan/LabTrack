#pragma once
#include <vector>
#include <string>
#include "../models/TA.h"

class TARepository {
private:
    std::string fileName;
public:
    TARepository(const std::string &file = "tas.bin");
    void save(const std::vector<TA>& v);
    std::vector<TA> load();
    int getNextId();
    void add(const TA &ta);
    std::vector<TA> getAll();
};
