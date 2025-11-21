#pragma once
#include <string>

class Room {
private:
    int id;
    int buildingId;
    std::string roomNumber;

public:
    Room() = default;
    Room(int id, int buildingId, const std::string& number)
        : id(id), buildingId(buildingId), roomNumber(number) {}

    int getId() const { return id; }
    int getBuildingId() const { return buildingId; }
    std::string getRoomNumber() const { return roomNumber; }
};
