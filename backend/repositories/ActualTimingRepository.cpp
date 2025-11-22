#include "ActualTimingRepository.h"

ActualTimingRepository::ActualTimingRepository(const std::string &file) : fileName(file) {}

std::vector<ActualTiming> ActualTimingRepository::getAllActualTimings() {
    // Minimal implementation: return empty vector until a proper storage format is defined.
    return {};
}

std::vector<ActualTiming> ActualTimingRepository::getActualTimingsByLabId(int labId) {
    // Minimal: filter ownerless storage (none) -> empty
    return {};
}
