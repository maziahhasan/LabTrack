#pragma once
#include "../models/ActualTiming.h"
#include <vector>
#include <string>

class ActualTimingRepository {
public:
    explicit ActualTimingRepository(const std::string &file = "actual_timings.bin");

    // Return all recorded actual timings
    std::vector<ActualTiming> getAllActualTimings();

    // Return timings filtered by lab id
    std::vector<ActualTiming> getActualTimingsByLabId(int labId);

    // alias used in UI
    std::vector<ActualTiming> getTimingsByLabId(int labId) { return getActualTimingsByLabId(labId); }
 

private:
    std::string fileName;
};
