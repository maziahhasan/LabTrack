#pragma once
#include <string>
using namespace std;

class ScheduleTiming {
private:
    string dayOfWeek;
    string expectedStart;
    string expectedEnd;

public:
    ScheduleTiming() = default;

    ScheduleTiming(const string& day, const string& start, const string& end)
        : dayOfWeek(day), expectedStart(start), expectedEnd(end) {}

    // getters
    string getDay() const { return dayOfWeek; }
    string getStart() const { return expectedStart; }
    string getEnd() const { return expectedEnd; }

    // setters
    void setDay(const string& d) { dayOfWeek = d; }
    void setStart(const string& s) { expectedStart = s; }
    void setEnd(const string& e) { expectedEnd = e; }
};
