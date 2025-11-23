#pragma once
#include <string>

// ActualTiming represents a recorded session. Fields are optional depending on usage.
class ActualTiming {
private:
    int labId = -1;         // Lab session ID
    int taId = -1;          // TA who attended
    std::string date;       // Date of session (YYYY-MM-DD)
    std::string startTime;  // Actual start time (HH:MM)
    std::string endTime;    // Actual end time (HH:MM)
    double durationHours = 0.0; // Duration in hours
    std::string notes;      // Optional notes (e.g., issues, remarks)

public:
    ActualTiming() = default;
    ActualTiming(const std::string &d, const std::string &s, const std::string &e)
        : date(d), startTime(s), endTime(e) {}
    ActualTiming(int lab, int ta, const std::string &d, const std::string &s, const std::string &e, double dur = 0.0, const std::string& n = "")
        : labId(lab), taId(ta), date(d), startTime(s), endTime(e), durationHours(dur), notes(n) {}

    // Getters
    int getLabId() const { return labId; }
    int getTaId() const { return taId; }
    std::string getDate() const { return date; }
    std::string getStartTime() const { return startTime; }
    std::string getEndTime() const { return endTime; }
    double getDuration() const { return durationHours; }
    std::string getNotes() const { return notes; }

    // Setters
    void setLabId(int id) { labId = id; }
    void setTaId(int id) { taId = id; }
    void setDate(const std::string &d) { date = d; }
    void setStartTime(const std::string &s) { startTime = s; }
    void setEndTime(const std::string &e) { endTime = e; }
    void setDuration(double h) { durationHours = h; }
    void setNotes(const std::string& n) { notes = n; }
};
