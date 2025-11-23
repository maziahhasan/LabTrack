#pragma once
#include "../repositories/LabRepository.h"
#include "../repositories/RoomRepository.h"
#include "../repositories/BuildingRepository.h"
#include "../models/User.h"

class LabService {
private:
    LabRepository &labRepo;
    RoomRepository &roomRepo;
    BuildingRepository &buildingRepo;
public:
    LabService(LabRepository &l, RoomRepository &r, BuildingRepository &b);

    // Only AcademicOfficer may add labs
    bool addLab(const User &actor, const Lab &lab);
    // Only AcademicOfficer may update lab status
    bool updateLabStatus(const User &actor, int labId, const std::string& status);
    // Only AcademicOfficer may assign TAs to a lab
    bool assignTAs(const User &actor, int labId, const std::vector<int>& taIds);
    // Only AcademicOfficer may update lab venue (room/building)
    bool updateLabVenue(const User &actor, int labId, int roomId, int buildingId);
    // Only AcademicOfficer may update lab schedule
    bool updateLabSchedule(const User &actor, int labId, const ScheduleTiming& schedule);

    // Only building attendant assigned to the building of the lab's room may add actual timing
    bool addActualTiming(const User &actor, int labId, const ActualTiming &t);

    // Query labs by various fields (role-based access enforced)
    std::vector<Lab> getLabsByInstructor(const User &actor, int instructorId);
    std::vector<Lab> getLabsByTA(const User &actor, int taId);
    std::vector<Lab> getLabsByBuilding(const User &actor, int buildingId);
    std::vector<Lab> getLabsByStatus(const User &actor, const std::string& status);
    Lab getLabById(const User &actor, int labId);
};
