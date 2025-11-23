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
    int requestMakeup(const User &actor, int labId, const std::string &date, const std::string &start, const std::string &end, const std::string& reason = "");

    // AcademicOfficer approves a makeup request; when approved, add the actual timing to lab
    bool approveMakeup(const User &actor, int requestId);

    // AcademicOfficer or HOD may reject a makeup request
    bool rejectMakeup(const User &actor, int requestId, const std::string& reason = "");

    // Query makeup requests by status, lab, or user
    std::vector<int> getRequestsByStatus(const User &actor, const std::string& status);
    std::vector<int> getRequestsByLab(const User &actor, int labId);
    std::vector<int> getRequestsByUser(const User &actor, int userId);
};
