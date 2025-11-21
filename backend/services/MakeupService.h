#pragma once
#include "../repositories/MakeupRequestRepository.h"
#include "../repositories/LabRepository.h"
#include "../models/User.h"

class MakeupService {
private:
    MakeupRequestRepository &mrRepo;
    LabRepository &labRepo;
public:
    MakeupService(MakeupRequestRepository &m, LabRepository &l);

    // Instructor requests makeup
    int requestMakeup(const User &actor, int labId, const std::string &date, const std::string &start, const std::string &end);

    // AcademicOfficer approves a makeup request; when approved, add the actual timing to lab
    bool approveMakeup(const User &actor, int requestId);
};
