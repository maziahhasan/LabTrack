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
    std::vector<Room> getAll();
};
