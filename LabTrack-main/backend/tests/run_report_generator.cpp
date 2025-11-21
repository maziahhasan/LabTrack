#include <iostream>
#include <filesystem>
#include "../repositories/LabRepository.h"
#include "../services/ReportService.h"
#include "../services/ReportGenerator.h"

int main() {
    namespace fs = std::filesystem;
    fs::create_directories("reports");

    LabRepository repo("test_labs.bin");
    ReportService rs(repo);
    ReportGenerator rg(rs);

    std::string weeklySchedulePath = "reports/weekly_schedule.txt";
    std::string weeklyTsPath = "reports/weekly_timesheets.txt";
    std::string labSummaryPath = "reports/lab_1_summary.txt";

    if (rg.generateWeeklyScheduleReport(weeklySchedulePath)) std::cout << "Generated " << weeklySchedulePath << "\n";
    else std::cout << "Failed to write weekly schedule\n";

    if (rg.generateWeeklyTimeSheetReport("2025-11-10", weeklyTsPath)) std::cout << "Generated " << weeklyTsPath << "\n";
    else std::cout << "Failed to write weekly time-sheets\n";

    if (rg.generateLabSessionSummary(1, "2025-01-01", "2025-12-31", labSummaryPath)) std::cout << "Generated " << labSummaryPath << "\n";
    else std::cout << "Failed to write lab summary\n";

    return 0;
}
