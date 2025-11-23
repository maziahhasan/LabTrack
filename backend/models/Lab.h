#pragma once
#include <vector>
#include <string>
#include "ScheduleTiming.h"
#include "ActualTiming.h"
#include "TA.h"

class Lab {
private:
    int id; // Unique lab ID
    std::string courseCode; // e.g., CS101
    std::string section;    // e.g., A, B, C
    int roomId{0};          // Venue (Room) ID
    int buildingId{0};      // Venue (Building) ID
    int instructorId{0};    // Instructor assigned
    ScheduleTiming schedule; // Scheduled timing (day, start, end)
    std::vector<int> taIds; // TA IDs assigned to this lab
    std::vector<ActualTiming> timeSheets; // Attendance/timesheet records
    std::string status = "Active"; // Lab status (Active/Inactive)

public:
    Lab() = default;

    Lab(int id, const std::string& code, const std::string& sec)
        : id(id), courseCode(code), section(sec) {}
    Lab(int id, const std::string& code, const std::string& sec, int room, int building)
        : id(id), courseCode(code), section(sec), roomId(room), buildingId(building) {}
    Lab(int id, const std::string& code, const std::string& sec, int room, int building, int instructorId, const ScheduleTiming& schedule)
        : id(id), courseCode(code), section(sec), roomId(room), buildingId(building), instructorId(instructorId), schedule(schedule) {}

    // Getters
    int getId() const { return id; }
    std::string getCourseCode() const { return courseCode; }
    std::string getSection() const { return section; }
    int getRoomId() const { return roomId; }
    int getBuildingId() const { return buildingId; }
    int getInstructorId() const { return instructorId; }
    ScheduleTiming getSchedule() const { return schedule; }
    std::string getStatus() const { return status; }

    // Setters
    void setRoomId(int r) { roomId = r; }
    void setBuildingId(int b) { buildingId = b; }
    void setInstructorId(int id) { instructorId = id; }
    void setSchedule(const ScheduleTiming& s) { schedule = s; }
    void setStatus(const std::string& s) { status = s; }

    // TA management
    void addTA(int taId) { taIds.push_back(taId); }
    void setTAs(const std::vector<int>& ids) { taIds = ids; }
    const std::vector<int>& getTAs() const { return taIds; }

    // Timesheet management
    void addActualTiming(const ActualTiming& ts) { timeSheets.push_back(ts); }
    void setTimeSheets(const std::vector<ActualTiming>& ts) { timeSheets = ts; }
    const std::vector<ActualTiming>& getTimeSheets() const { return timeSheets; }

    // UI/compatibility helpers
    std::string getName() const { return courseCode + (section.empty() ? "" : (" " + section)); }
};
