#include "BuildingRepository.h"
#include <algorithm>

static void writeString(std::ofstream &out, const std::string &s) {
    int len = s.length(); out.write((char*)&len, sizeof(len)); out.write(s.c_str(), len);
}
static std::string readString(std::ifstream &in) {
    int len; in.read((char*)&len, sizeof(len)); char *buffer = new char[len + 1]; in.read(buffer, len); buffer[len] = '\0'; std::string s(buffer); delete[] buffer; return s;
}

BuildingRepository::BuildingRepository(const std::string &file) { fileName = file; }

void BuildingRepository::save(const std::vector<Building>& v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (auto &b : v) {
        int id = b.getId(); out.write((char*)&id, sizeof(id));
        writeString(out, b.getName());
        out.write((char*)&b.getAttendantId(), sizeof(int));
        // write room ids
        auto rooms = b.getRooms(); int count = rooms.size(); out.write((char*)&count, sizeof(count));
        for (int r : rooms) out.write((char*)&r, sizeof(r));
    }
}

std::vector<Building> BuildingRepository::load() {
    std::vector<Building> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        std::string name = readString(in);
        int att; in.read((char*)&att, sizeof(att));
        Building b(id, name, att);
        int rcount; in.read((char*)&rcount, sizeof(rcount));
        for (int j = 0; j < rcount; ++j) {
            int rid; in.read((char*)&rid, sizeof(rid)); b.addRoom(rid);
        }
        outv.push_back(b);
    }
    return outv;
}

int BuildingRepository::getNextId() { auto v = load(); int maxId = 0; for (auto &b : v) if (b.getId() > maxId) maxId = b.getId(); return maxId + 1; }

void BuildingRepository::add(const Building &b) { auto v = load(); v.push_back(b); save(v); }

std::vector<Building> BuildingRepository::getAll() { return load(); }

bool BuildingRepository::setAttendant(int buildingId, int userId) {
    auto v = load();
    bool found = false;
    for (auto &b : v) {
        if (b.getId() == buildingId) { b.setAttendantId(userId); found = true; break; }
    }
    if (found) save(v);
    return found;
}
