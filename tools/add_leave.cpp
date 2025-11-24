#include <iostream>
#include "backend/repositories/ActualTimingRepository.h"
#include "backend/models/ActualTiming.h"

int main() {
    ActualTimingRepository repo("actual_timings.bin");
    
    // Add a leave entry for lab 1 (00:00 - 00:00, duration 0)
    ActualTiming leave1(1, 5, "2024-11-04", "00:00", "00:00", 0.0, "Leave");
    ActualTiming leave2(1, 5, "2024-11-18", "00:00", "00:00", 0.0, "Leave");
    ActualTiming leave3(2, 5, "2024-11-06", "00:00", "00:00", 0.0, "Leave");
    
    repo.add(leave1);
    repo.add(leave2);
    repo.add(leave3);
    
    std::cout << "Added 3 leave entries (00:00 - 00:00):\n";
    std::cout << "  - Lab 1: 2024-11-04\n";
    std::cout << "  - Lab 1: 2024-11-18\n";
    std::cout << "  - Lab 2: 2024-11-06\n";
    
    return 0;
}
