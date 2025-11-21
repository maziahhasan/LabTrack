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
    int roomId{0};
    int instructorId;
    ScheduleTiming schedule;
    std::vector<TA> tas;
    std::vector<ActualTiming> timeSheets;

public:
    Lab() = default;

    Lab(int id, const std::string& code, const std::string& sec)
        : id(id), courseCode(code), section(sec) {}

    Lab(int id, const std::string& code, const std::string& sec, int room)
        : id(id), courseCode(code), section(sec), roomId(room) {}

    int getId() const { return id; }
    std::string getCourseCode() const { return courseCode; }
    std::string getSection() const { return section; }
    int getInstructorId() const { return instructorId; }
    ScheduleTiming getSchedule() const { return schedule; }
    int getRoomId() const { return roomId; }

    void setInstructorId(int id) { instructorId = id; }
    void setSchedule(const ScheduleTiming& s) { schedule = s; }
    void setRoomId(int r) { roomId = r; }
    void addTA(const TA& ta) { tas.push_back(ta); }
    void addActualTiming(const ActualTiming& ts) { timeSheets.push_back(ts); }

    const std::vector<TA>& getTAs() const { return tas; }
    const std::vector<ActualTiming>& getTimeSheets() const { return timeSheets; }
};
