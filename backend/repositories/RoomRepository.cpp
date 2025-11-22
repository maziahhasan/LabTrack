#include "RoomRepository.h"
#include <algorithm>

static void writeString(std::ofstream &out, const std::string &s) {
    int len = s.length(); out.write((char*)&len, sizeof(len)); out.write(s.c_str(), len);
}
static std::string readString(std::ifstream &in) {
    int len; in.read((char*)&len, sizeof(len)); char *buffer = new char[len + 1]; in.read(buffer, len); buffer[len] = '\0'; std::string s(buffer); delete[] buffer; return s;
}

RoomRepository::RoomRepository(const std::string &file) { fileName = file; }

void RoomRepository::save(const std::vector<Room>& v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (auto &r : v) {
        int id = r.getId(); out.write((char*)&id, sizeof(id));
        int bid = r.getBuildingId(); out.write((char*)&bid, sizeof(bid));
        writeString(out, r.getRoomNumber());
    }
}

std::vector<Room> RoomRepository::load() {
    std::vector<Room> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        int bid; in.read((char*)&bid, sizeof(bid));
        std::string number = readString(in);
        outv.push_back(Room(id, bid, number));
    }
    return outv;
}

int RoomRepository::getNextId() { auto v = load(); int maxId = 0; for (auto &r : v) if (r.getId() > maxId) maxId = r.getId(); return maxId + 1; }

void RoomRepository::add(const Room &r) { auto v = load(); v.push_back(r); save(v); }

std::vector<Room> RoomRepository::getAll() { return load(); }
