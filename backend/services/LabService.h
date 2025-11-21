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

    // Only building attendant assigned to the building of the lab's room may add actual timing
    bool addActualTiming(const User &actor, int labId, const ActualTiming &t);
};
