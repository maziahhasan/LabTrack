#pragma once
#include <string>
#include "ReportService.h"

class ReportGenerator {
private:
    ReportService &service;
public:
    ReportGenerator(ReportService &srv);

    // Produce readable weekly schedule (all labs) into a text file
    bool generateWeeklyScheduleReport(const std::string &outPath);

    // Produce a filled time sheet report for all labs in a given week (monday date)
    bool generateWeeklyTimeSheetReport(const std::string &mondayDate, const std::string &outPath);

    // Produce a time sheet summary for all sessions of a lab between start and end dates
    bool generateLabSessionSummary(int labId, const std::string &startDate, const std::string &endDate, const std::string &outPath);
};
