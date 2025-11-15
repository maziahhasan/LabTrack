#pragma once
#include <string>
#include <vector>

class Building {
private:
    int id;
    std::string name;
    std::vector<int> roomIds;  // stores room ids
    int attendantId;

public:
    Building() = default;
    Building(int id, const std::string& name, int attendant)
        : id(id), name(name), attendantId(attendant) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAttendantId() const { return attendantId; }

    void addRoom(int roomId) { roomIds.push_back(roomId); }
    const std::vector<int>& getRooms() const { return roomIds; }
};
