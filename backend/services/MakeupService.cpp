#include "MakeupService.h"
#include "../utils/DateUtils.h"

MakeupService::MakeupService(MakeupRequestRepository &m, LabRepository &l) : mrRepo(m), labRepo(l) {}

int MakeupService::requestMakeup(const User &actor, int labId, const std::string &date, const std::string &start, const std::string &end, const std::string& reason) {
    if (actor.getRole() != "Instructor") return -1;
    int id = mrRepo.getNextId();
    std::string timeRange = start + "-" + end;
    // Get room from the lab - default to lab's room (0 if not set)
    Lab lab = labRepo.getById(labId);
    int roomId = (lab.getId() != -1) ? lab.getRoomId() : 0;
    MakeupRequest m(id, labId, actor.getId(), roomId, date, timeRange, reason, "Pending");
    mrRepo.add(m);
    return id;
}

bool MakeupService::approveMakeup(const User &actor, int requestId) {
    if (actor.getRole() != "AcademicOfficer") return false;
    auto requests = mrRepo.load();
    for (auto &r : requests) {
        if (r.getId() == requestId) {
            if (r.getStatus() != "Pending") return false;
            // Parse time range
            std::string timeStr = r.getTime();
            size_t dashPos = timeStr.find('-');
            if (dashPos == std::string::npos) return false;
            std::string start = timeStr.substr(0, dashPos);
            std::string end = timeStr.substr(dashPos + 1);
            
            // add actual timing to lab
            Lab lab = labRepo.getById(r.getLabId());
            if (lab.getId() == -1) return false;
            ActualTiming timing(r.getLabId(), -1, r.getDate(), start, end);
            lab.addActualTiming(timing);
            labRepo.update(lab);
            r.setStatus("Approved");
            mrRepo.update(r);
            return true;
        }
    }
    return false;
}
