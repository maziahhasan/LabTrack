#pragma once
#include <string>
#include <vector>
#include "../models/Lab.h"
#include "../repositories/LabRepository.h"
#include "../repositories/InstructorRepository.h"
#include "../repositories/TARepository.h"
#include "../repositories/RoomRepository.h"
#include "../repositories/BuildingRepository.h"
#include "../repositories/ActualTimingRepository.h"

struct TimeSheetSummary {
    double totalHours;
    int leaves;
};

class ReportService {
private:
    LabRepository &labRepo;
public:
    // simple constructor: accept only lab repo
    ReportService(LabRepository &repo);
    // compatibility: allow constructing with full set of repositories (UI passes these)
    ReportService(LabRepository &repo, InstructorRepository &irepo, TARepository &trepo, RoomRepository &rrepo, BuildingRepository &brepo, ActualTimingRepository &atrepo);

    // Returns list of labs with schedule for the week (Mon-Sun)
    std::vector<Lab> weeklySchedule();

    // returns labs time sheets for a date range
    std::vector<Lab> labsWithTimesheetsForWeek(const std::string &mondayDate);

    // compute summary for a specific lab in a date range
    TimeSheetSummary computeTimeSheetSummary(int labId, const std::string &startDate, const std::string &endDate);
    
    // expose single-lab lookup
    Lab getLabById(int id);
};
