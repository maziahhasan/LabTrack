#pragma once
#include <string>
using namespace std;

class ScheduleTiming {
private:
    string dayOfWeek;      // e.g., Monday
    string expectedStart;  // e.g., 09:00
    string expectedEnd;    // e.g., 11:00

public:
    ScheduleTiming() = default;
    ScheduleTiming(const string& day, const string& start, const string& end)
        : dayOfWeek(day), expectedStart(start), expectedEnd(end) {}

    // Getters
    string getDay() const { return dayOfWeek; }
    string getStart() const { return expectedStart; }
    string getEnd() const { return expectedEnd; }

    // String representation for reporting
    std::string toString() const { return dayOfWeek + " " + expectedStart + "-" + expectedEnd; }
    operator std::string() const { return toString(); }

    // Setters
    void setDay(const string& d) { dayOfWeek = d; }
    void setStart(const string& s) { expectedStart = s; }
    void setEnd(const string& e) { expectedEnd = e; }
};
