#pragma once
#include <string>
#include <vector>
#include "../models/Lab.h"
#include "../models/User.h"
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
    // Optionally store references to other repositories for richer reporting
    InstructorRepository *instrRepo = nullptr;
    TARepository *taRepo = nullptr;
    RoomRepository *roomRepo = nullptr;
    BuildingRepository *buildingRepo = nullptr;
    ActualTimingRepository *actualTimingRepo = nullptr;
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

    // New: reporting by venue, section, TA, instructor, etc.
    std::vector<Lab> getLabsByVenue(const User& actor, int buildingId, int roomId);
    std::vector<Lab> getLabsBySection(const User& actor, const std::string& section);
    std::vector<Lab> getLabsByTA(const User& actor, int taId);
    std::vector<Lab> getLabsByInstructor(const User& actor, int instructorId);
    // New: generate summary report for all labs in a date range
    std::vector<TimeSheetSummary> summaryForAllLabs(const User& actor, const std::string& startDate, const std::string& endDate);
};
