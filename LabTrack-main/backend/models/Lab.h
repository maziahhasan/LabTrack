#pragma once
#include <vector>
#include <string>
#include "ScheduleTiming.h"
#include "ActualTiming.h"
#include "TA.h"

class Lab {
private:
    int id;
    std::string courseCode;
    std::string section;
    int instructorId;
    ScheduleTiming schedule;
    std::vector<TA> tas;
    std::vector<ActualTiming> timeSheets;

public:
    Lab() = default;

    Lab(int id, const std::string& code, const std::string& sec)
        : id(id), courseCode(code), section(sec) {}

    int getId() const { return id; }
    std::string getCourseCode() const { return courseCode; }
    std::string getSection() const { return section; }
    int getInstructorId() const { return instructorId; }
    ScheduleTiming getSchedule() const { return schedule; }

    void setInstructorId(int id) { instructorId = id; }
    void setSchedule(const ScheduleTiming& s) { schedule = s; }
    void addTA(const TA& ta) { tas.push_back(ta); }
    void addActualTiming(const ActualTiming& ts) { timeSheets.push_back(ts); }

    const std::vector<TA>& getTAs() const { return tas; }
    const std::vector<ActualTiming>& getTimeSheets() const { return timeSheets; }
};
