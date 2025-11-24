#include <iostream>
#include "../backend/repositories/ActualTimingRepository.h"
#include "../backend/models/ActualTiming.h"

int main() {
    ActualTimingRepository repo("actual_timings.bin");
    
    // Add a timesheet entry for lab ID 1 (CS1001) by attendant ID 5 (att_a)
    // Date: today, Time: 09:00 - 11:00, Duration: 2.0 hours
    ActualTiming t1(1, 5, "2025-11-24", "09:00", "11:00", 2.0, "Completed");
    repo.add(t1);
    
    // Add another entry for lab ID 2 (CS2001)
    ActualTiming t2(2, 5, "2025-11-24", "14:00", "16:00", 2.0, "Completed");
    repo.add(t2);
    
    std::cout << "Added 2 timesheet entries for labs in Engineering Block.\n";
    std::cout << "Lab 1 (CS1001): 2025-11-24 09:00-11:00\n";
    std::cout << "Lab 2 (CS2001): 2025-11-24 14:00-16:00\n";
    
    return 0;
}
