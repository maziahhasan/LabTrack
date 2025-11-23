#pragma once
#include <string>

class Room {
private:
    int id = -1;              // Room ID
    int buildingId = -1;      // Building ID
    std::string roomNumber;   // Room number or code
    int capacity = 0;         // Room capacity (optional)
    std::string type;         // e.g., "Lab", "Lecture", etc.

public:
    Room() = default;
    Room(int id, int buildingId, const std::string& number, int cap = 0, const std::string& t = "Lab")
        : id(id), buildingId(buildingId), roomNumber(number), capacity(cap), type(t) {}

    int getId() const { return id; }
    int getBuildingId() const { return buildingId; }
    std::string getRoomNumber() const { return roomNumber; }
    int getCapacity() const { return capacity; }
    std::string getType() const { return type; }
    std::string getName() const { return roomNumber; }

    void setCapacity(int cap) { capacity = cap; }
    void setType(const std::string& t) { type = t; }
};
