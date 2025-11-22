#pragma once
#include <string>

// ActualTiming represents a recorded session. Fields are optional depending on usage.
class ActualTiming {
private:
    int labId = -1;
    int taId = -1;
    std::string date;
    std::string startTime;
    std::string endTime;
    double durationHours = 0.0; // optional cached duration

public:
    ActualTiming() = default;

    ActualTiming(const std::string &d, const std::string &s, const std::string &e)
        : date(d), startTime(s), endTime(e) {}

    ActualTiming(int lab, int ta, const std::string &d, const std::string &s, const std::string &e, double dur = 0.0)
        : labId(lab), taId(ta), date(d), startTime(s), endTime(e), durationHours(dur) {}

    int getLabId() const { return labId; }
    int getTaId() const { return taId; }
    std::string getDate() const { return date; }
    std::string getStartTime() const { return startTime; }
    std::string getEndTime() const { return endTime; }
    // Compatibility accessors used by some services
    std::string getStart() const { return getStartTime(); }
    std::string getEnd() const { return getEndTime(); }
    double getDuration() const { return durationHours; }

    void setLabId(int id) { labId = id; }
    void setTaId(int id) { taId = id; }
    void setDate(const std::string &d) { date = d; }
    void setStartTime(const std::string &s) { startTime = s; }
    void setEndTime(const std::string &e) { endTime = e; }
    void setDuration(double h) { durationHours = h; }
};
