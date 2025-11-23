#include "ReportService.h"
#include "../utils/DateUtils.h"
#include <algorithm>
#include <cmath>

ReportService::ReportService(LabRepository &repo) : labRepo(repo) {}

ReportService::ReportService(LabRepository &repo, InstructorRepository &irepo, TARepository &trepo, RoomRepository &rrepo, BuildingRepository &brepo, ActualTimingRepository &atrepo)
    : labRepo(repo) {
    // currently we only need labRepo in implementations; other repositories are accepted for compatibility
    (void)irepo; (void)trepo; (void)rrepo; (void)brepo; (void)atrepo;
}

std::vector<Lab> ReportService::weeklySchedule() {
    // return list of all labs with schedule info
    return labRepo.getAll();
}

std::vector<Lab> ReportService::labsWithTimesheetsForWeek(const std::string &mondayDate) {
    // return labs which have any actual timings between mondayDate and mondayDate + 6 days
    auto labs = labRepo.getAll();
    std::vector<Lab> result;
    long start = DateUtils::parseDate(mondayDate);
    long end = start + 6*24*60*60;
    for (const Lab &lab : labs) {
        const auto &times = lab.getTimeSheets();
        for (const auto &t: times) {
            long d = DateUtils::parseDate(t.getDate());
            if (d >= start && d <= end) { result.push_back(lab); break; }
        }
    }
    return result;
}

TimeSheetSummary ReportService::computeTimeSheetSummary(int labId, const std::string &startDate, const std::string &endDate) {
    TimeSheetSummary s{0.0, 0};
    Lab lab = labRepo.getById(labId);
    if (lab.getId() == -1) return s;
    long start = DateUtils::parseDate(startDate);
    long end = DateUtils::parseDate(endDate);

    // compute expected occurrences between dates by matching day names
    std::string dayStr = lab.getSchedule().getDay();
    std::string dow = DateUtils::normalizeDay(dayStr);

    int expectedSessions = 0;
    for (long cur = start; cur <= end; cur += 24*60*60) {
        if (DateUtils::dayOfWeek(cur) == dow) expectedSessions++;
    }

    // count actual sheets in range and sum durations
    int actualCount = 0;
    for (const ActualTiming &t : lab.getTimeSheets()) {
        long d = DateUtils::parseDate(t.getDate());
        if (d >= start && d <= end) {
            actualCount++;
            s.totalHours += DateUtils::hoursBetween(t.getStartTime(), t.getEndTime());
        }
    }

    s.leaves = std::max(0, expectedSessions - actualCount);
    return s;
}

Lab ReportService::getLabById(int id) {
    return labRepo.getById(id);
}
