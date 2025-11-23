#pragma once
#include <string>
#include <vector>

class Building {
private:
    int id = -1;                       // Building ID
    std::string name;                  // Building name
    std::vector<int> roomIds;          // Room IDs in this building
    int attendantId = -1;              // Attendant (user) ID
    std::string location;              // Optional: address or location string

public:
    Building() = default;
    Building(int id, const std::string& name, int attendant, const std::string& loc = "")
        : id(id), name(name), attendantId(attendant), location(loc) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAttendantId() const { return attendantId; }
    std::string getLocation() const { return location; }

    void setAttendantId(int id) { attendantId = id; }
    void setLocation(const std::string& loc) { location = loc; }

    void addRoom(int roomId) { roomIds.push_back(roomId); }
    void setRooms(const std::vector<int>& ids) { roomIds = ids; }
    const std::vector<int>& getRooms() const { return roomIds; }
};
