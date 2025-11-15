#pragma once
#include <string>

class ActualTiming {
private:
    std::string date;
    std::string actualStart;
    std::string actualEnd;

public:
    ActualTiming() = default;

    ActualTiming(const std::string& d, const std::string& s, const std::string& e)
        : date(d), actualStart(s), actualEnd(e) {}

    std::string getDate() const { return date; }
    std::string getStart() const { return actualStart; }
    std::string getEnd() const { return actualEnd; }

    void setDate(const std::string& d) { date = d; }
    void setStart(const std::string& s) { actualStart = s; }
    void setEnd(const std::string& e) { actualEnd = e; }
};
