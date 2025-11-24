#include <iostream>
#include "../backend/repositories/ActualTimingRepository.h"

int main() {
    ActualTimingRepository repo("actual_timings.bin");
    
    auto all = repo.getAllActualTimings();
    std::cout << "Total timings in actual_timings.bin: " << all.size() << "\n";
    
    for (const auto& t : all) {
        std::cout << "Lab ID: " << t.getLabId() 
                  << " Date: " << t.getDate()
                  << " Start: " << t.getStartTime()
                  << " End: " << t.getEndTime()
                  << " Duration: " << t.getDuration() << "\n";
    }
    
    return 0;
}
