#include "ReportGenerator.h"
#include <fstream>
#include <iomanip>
#include "../utils/DateUtils.h"

ReportGenerator::ReportGenerator(ReportService &srv) : service(srv) {}

bool ReportGenerator::generateWeeklyScheduleReport(const std::string &outPath) {
    auto labs = service.weeklySchedule();
    std::ofstream out(outPath);
    if (!out.is_open()) return false;

    out << "Weekly Lab Schedule\n";
    out << "Generated: " << __DATE__ << "\n\n";
    out << std::left << std::setw(6) << "ID" << std::setw(12) << "Course" << std::setw(8) << "Section" << std::setw(10) << "Day" << std::setw(8) << "Start" << std::setw(8) << "End" << "TAs" << "\n";
    out << std::string(80, '-') << "\n";

    for (const Lab &l : labs) {
        std::string taNames;
        const auto &taIds = l.getTAs();
        for (size_t i = 0; i < taIds.size(); ++i) {
            taNames += std::to_string(taIds[i]);
            if (i + 1 < taIds.size()) taNames += ", ";
        }
        out << std::left << std::setw(6) << l.getId()
            << std::setw(12) << l.getCourseCode()
            << std::setw(8) << l.getSection()
            << std::setw(10) << l.getSchedule().getDay()
            << std::setw(8) << l.getSchedule().getStart()
            << std::setw(8) << l.getSchedule().getEnd()
            << taNames << "\n";
    }

    out.close();
    return true;
}

bool ReportGenerator::generateWeeklyTimeSheetReport(const std::string &mondayDate, const std::string &outPath) {
    auto labs = service.labsWithTimesheetsForWeek(mondayDate);
    std::ofstream out(outPath);
    if (!out.is_open()) return false;

    out << "Weekly Filled Time-sheets (week starting " << mondayDate << ")\n";
    out << "Generated: " << __DATE__ << "\n\n";
    for (const Lab &l : labs) {
        out << "Lab " << l.getCourseCode() << "-" << l.getSection() << " (ID:" << l.getId() << ")\n";
        out << "Instructor ID: " << l.getInstructorId() << "\n";
        out << "Schedule: " << l.getSchedule().getDay() << " " << l.getSchedule().getStart() << "-" << l.getSchedule().getEnd() << "\n";
        out << "Time Sheets:\n";
        out << std::setw(12) << "Date" << std::setw(8) << "Start" << std::setw(8) << "End" << std::setw(12) << "Duration(h)" << "\n";
        out << std::string(48, '-') << "\n";
        for (const auto &t : l.getTimeSheets()) {
            double hrs = DateUtils::hoursBetween(t.getStartTime(), t.getEndTime());
            out << std::setw(12) << t.getDate() << std::setw(8) << t.getStartTime() << std::setw(8) << t.getEndTime() << std::setw(12) << std::fixed << std::setprecision(2) << hrs << "\n";
        }
        out << "\n";
    }

    out.close();
    return true;
}

bool ReportGenerator::generateLabSessionSummary(int labId, const std::string &startDate, const std::string &endDate, const std::string &outPath) {
    std::ofstream out(outPath);
    if (!out.is_open()) return false;

    auto summary = service.computeTimeSheetSummary(labId, startDate, endDate);
    Lab lab = service.getLabById(labId);
    if (lab.getId() == -1) {
        out << "Lab not found: " << labId << "\n";
        out.close();
        return false;
    }

    out << "Time Sheet Summary for Lab " << lab.getCourseCode() << "-" << lab.getSection() << " (ID:" << lab.getId() << ")\n";
    out << "Period: " << startDate << " to " << endDate << "\n";
    out << "Instructor ID: " << lab.getInstructorId() << "\n";
    out << "Expected sessions per schedule between dates computed using schedule day.\n";
    out << "Total recorded contact hours: " << std::fixed << std::setprecision(2) << summary.totalHours << " hours\n";
    out << "Total leaves (missed sessions): " << summary.leaves << "\n";

    out << "\nRecorded sessions:\n";
    out << std::setw(12) << "Date" << std::setw(8) << "Start" << std::setw(8) << "End" << std::setw(12) << "Duration(h)" << "\n";
    out << std::string(48, '-') << "\n";
    for (const auto &t : lab.getTimeSheets()) {
        long d = DateUtils::parseDate(t.getDate());
        long s = DateUtils::parseDate(startDate);
        long e = DateUtils::parseDate(endDate);
        if (d >= s && d <= e) {
            double hrs = DateUtils::hoursBetween(t.getStartTime(), t.getEndTime());
            out << std::setw(12) << t.getDate() << std::setw(8) << t.getStartTime() << std::setw(8) << t.getEndTime() << std::setw(12) << std::fixed << std::setprecision(2) << hrs << "\n";
        }
    }

    out.close();
    return true;
}
