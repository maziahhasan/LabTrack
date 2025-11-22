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
    // convenience lookup
    // Return pointer (caller may assume ownership) to match UI usage patterns
    TA* getTAById(int id) {
        auto v = load();
        for (const auto &t : v) if (t.getId() == id) return new TA(t);
        return nullptr;
    }
};
