#include <iostream>
#include "../repositories/LabRepository.h"
#include <string>

int main() {
    LabRepository repo("test_labs.bin");

    // create sample lab
    int id = repo.getNextId();
    Lab lab(id, "CS101", "A");
    lab.setInstructorId(1001);
    std::string monday = "Monday";
    lab.setSchedule(ScheduleTiming(monday, "09:00", "11:00"));
    lab.addTA(TA(2001, "Alice"));
    lab.addTA(TA(2002, "Bob"));
    lab.addActualTiming(ActualTiming("2025-11-10", "09:05", "11:00"));

    repo.add(lab);

    auto labs = repo.getAll();
    std::cout << "Saved labs count: " << labs.size() << std::endl;
    for (const Lab &l : labs) {
        std::cout << "Lab id: " << l.getId() << " course: " << l.getCourseCode()
                  << " sec: " << l.getSection() << " instr: " << l.getInstructorId() << std::endl;
    }

    return 0;
}