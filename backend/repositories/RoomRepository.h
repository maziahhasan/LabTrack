#pragma once
#include <vector>
#include <fstream>
#include "../models/Room.h"

class RoomRepository {
private:
    std::string fileName;
public:
    RoomRepository(const std::string &file = "rooms.bin");
    void save(const std::vector<Room>& v);
    std::vector<Room> load();
    int getNextId();
    void add(const Room &r);
    bool update(const Room &r);
    std::vector<Room> getAll();
    // New queries for new model fields
    std::vector<Room> getRoomsByBuildingId(int buildingId);
    std::vector<Room> getRoomsByType(const std::string& type);
    std::vector<Room> getRoomsByCapacity(int minCapacity);
    // Return pointer (caller may assume ownership) to match UI usage
    Room* getRoomById(int id) {
        auto v = load();
        for (const auto &r : v) if (r.getId() == id) return new Room(r);
        return nullptr;
    }
};
