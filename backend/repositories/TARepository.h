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
    bool update(const TA &ta);
    bool remove(int id);
    std::vector<TA> getAll();
    // New queries for new model fields
    std::vector<TA> getTAsByStatus(const std::string& status);
    std::vector<TA> getTAsByEmail(const std::string& email);
    // Return pointer (caller may assume ownership) to match UI usage patterns
    TA* getTAById(int id) {
        auto v = load();
        for (const auto &t : v) if (t.getId() == id) return new TA(t);
        return nullptr;
    }
};
