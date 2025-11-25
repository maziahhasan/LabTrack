#pragma once
#include <string>
using namespace std;

class ScheduleTiming {
private:
    string dayOfWeek;      // e.g., Monday
    string expectedStart;  // e.g., 09:00
    string expectedEnd;    // e.g., 11:00
    string semesterStart;  // e.g., 2025-09-01
    string semesterEnd;    // e.g., 2025-12-31

public:
    ScheduleTiming() = default;
    ScheduleTiming(const string& day, const string& start, const string& end)
        : dayOfWeek(day), expectedStart(start), expectedEnd(end) {}
    ScheduleTiming(const string& day, const string& start, const string& end, const string& semStart, const string& semEnd)
        : dayOfWeek(day), expectedStart(start), expectedEnd(end), semesterStart(semStart), semesterEnd(semEnd) {}

    // Getters
    string getDay() const { return dayOfWeek; }
    string getStart() const { return expectedStart; }
    string getEnd() const { return expectedEnd; }
    string getSemesterStart() const { return semesterStart; }
    string getSemesterEnd() const { return semesterEnd; }

    // String representation for reporting
    std::string toString() const { return dayOfWeek + " " + expectedStart + "-" + expectedEnd; }
    operator std::string() const { return toString(); }

    // Setters
    void setDay(const string& d) { dayOfWeek = d; }
    void setStart(const string& s) { expectedStart = s; }
    void setEnd(const string& e) { expectedEnd = e; }
    void setSemesterStart(const string& s) { semesterStart = s; }
    void setSemesterEnd(const string& e) { semesterEnd = e; }
};
