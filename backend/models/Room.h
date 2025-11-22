#pragma once
#include <string>

class Room {
private:
    int id = -1;
    int buildingId = -1;
    std::string roomNumber;

public:
    Room() = default;
    Room(int id, int buildingId, const std::string& number)
        : id(id), buildingId(buildingId), roomNumber(number) {}

    int getId() const { return id; }
    int getBuildingId() const { return buildingId; }
    std::string getRoomNumber() const { return roomNumber; }
    // convenience
    std::string getName() const { return roomNumber; }
};
