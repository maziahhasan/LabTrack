#include "MakeupService.h"
#include "../utils/DateUtils.h"

MakeupService::MakeupService(MakeupRequestRepository &m, LabRepository &l) : mrRepo(m), labRepo(l) {}

int MakeupService::requestMakeup(const User &actor, int labId, const std::string &date, const std::string &start, const std::string &end) {
    if (actor.getRole() != "Instructor") return -1;
    int id = mrRepo.getNextId();
    MakeupRequest m(id, labId, actor.getId(), date, start, end, "pending");
    mrRepo.add(m);
    return id;
}

bool MakeupService::approveMakeup(const User &actor, int requestId) {
    if (actor.getRole() != "AcademicOfficer") return false;
    auto requests = mrRepo.load();
    for (auto &r : requests) {
        if (r.getId() == requestId) {
            if (r.getStatus() != "pending") return false;
            // add actual timing to lab
            Lab lab = labRepo.getById(r.getLabId());
            if (lab.getId() == -1) return false;
            lab.addActualTiming(ActualTiming(r.getDate(), r.getStart(), r.getEnd()));
            labRepo.update(lab);
            r.setStatus("approved");
            mrRepo.update(r);
            return true;
        }
    }
    return false;
}
