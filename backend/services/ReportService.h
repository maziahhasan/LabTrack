#pragma once
#include <string>
#include <vector>
#include "../models/Lab.h"
#include "../repositories/LabRepository.h"

struct TimeSheetSummary {
    double totalHours;
    int leaves;
};

class ReportService {
private:
    LabRepository &labRepo;
public:
    ReportService(LabRepository &repo);

    // Returns list of labs with schedule for the week (Mon-Sun)
    std::vector<Lab> weeklySchedule();

    // returns labs time sheets for a date range
    std::vector<Lab> labsWithTimesheetsForWeek(const std::string &mondayDate);

    // compute summary for a specific lab in a date range
    TimeSheetSummary computeTimeSheetSummary(int labId, const std::string &startDate, const std::string &endDate);
    
    // expose single-lab lookup
    Lab getLabById(int id);
};
