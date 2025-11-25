#pragma once
#include "../models/ActualTiming.h"
#include <vector>
#include <string>

class ActualTimingRepository {
private:
    std::string fileName;
public:
    explicit ActualTimingRepository(const std::string &file = "actual_timings.bin");

    // Return all recorded actual timings
    std::vector<ActualTiming> getAllActualTimings();

    // Return timings filtered by lab id
    std::vector<ActualTiming> getActualTimingsByLabId(int labId);
    // Return timings filtered by TA id
    std::vector<ActualTiming> getActualTimingsByTAId(int taId);
    // Return timings filtered by date
    std::vector<ActualTiming> getActualTimingsByDate(const std::string& date);

    // Add/update a timing record
    void add(const ActualTiming& timing);
    bool update(const ActualTiming& timing);
    bool remove(int labId, const std::string& date);
    bool removeByLabId(int labId);

    // alias used in UI
    std::vector<ActualTiming> getTimingsByLabId(int labId) { return getActualTimingsByLabId(labId); }
};
