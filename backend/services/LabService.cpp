#include "LabService.h"
#include "../services/AuthService.h"

LabService::LabService(LabRepository &l, RoomRepository &r, BuildingRepository &b) : labRepo(l), roomRepo(r), buildingRepo(b) {}

bool LabService::addLab(const User &actor, const Lab &lab) {
    if (actor.getRole() != "AcademicOfficer") return false;
    labRepo.add(lab);
    return true;
}

bool LabService::addActualTiming(const User &actor, int labId, const ActualTiming &t) {
    Lab lab = labRepo.getById(labId);
    if (lab.getId() == -1) return false;
    int roomId = lab.getRoomId();
    auto rooms = roomRepo.load();
    int buildingId = -1;
    for (const auto &r : rooms) { if (r.getId() == roomId) { buildingId = r.getBuildingId(); break; } }
    if (buildingId == -1) return false;
    auto buildings = buildingRepo.load();
    int attendant = -1;
    for (const auto &b : buildings) { if (b.getId() == buildingId) { attendant = b.getAttendantId(); break; } }
    if (attendant == -1) return false;
    if (actor.getId() != attendant && actor.getRole() != "AcademicOfficer") return false; // only attendant or academic officer

    // append timing
    lab.addActualTiming(t);
    labRepo.update(lab);
    return true;
}
