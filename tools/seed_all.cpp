#include <iostream>
#include <vector>
#include <string>
#include "../backend/repositories/UserRepository.h"
#include "../backend/repositories/InstructorRepository.h"
#include "../backend/repositories/TARepository.h"
#include "../backend/repositories/RoomRepository.h"
#include "../backend/repositories/BuildingRepository.h"
#include "../backend/repositories/LabRepository.h"
#include "../backend/repositories/ActualTimingRepository.h"
#include "../backend/repositories/MakeupRequestRepository.h"

int main() {
    // Users
    UserRepository userRepo("users.bin");
    userRepo.saveAll({}); // clear
    int uid = userRepo.getNextId();
    userRepo.add(User(uid++, "admin", "adminpass", "AcademicOfficer", "admin@uni.edu"));
    userRepo.add(User(uid++, "ta_a", "tapass", "TA", "ta_a@uni.edu"));
    userRepo.add(User(uid++, "instr_a", "instrpass", "Instructor", "instr_a@uni.edu"));
    userRepo.add(User(uid++, "hod_a", "hodpass", "HOD", "hod_a@uni.edu"));
    userRepo.add(User(uid++, "att_a", "attpass", "Attendant", "att_a@uni.edu"));

    // Instructors
    InstructorRepository instrRepo("instructors.bin");
    instrRepo.save({});
    int iid = instrRepo.getNextId();
    // Link to user ID 3 (instr_a)
    instrRepo.add(Instructor(iid++, "instr_a", "instr_a@uni.edu"));
    instrRepo.add(Instructor(iid++, "instr2", "instr2@uni.edu"));

    // TAs
    TARepository taRepo("tas.bin");
    taRepo.save({});
    int tid = taRepo.getNextId();
    taRepo.add(TA(tid++, "ta1", "ta1@uni.edu"));
    taRepo.add(TA(tid++, "ta2", "ta2@uni.edu"));
    taRepo.add(TA(tid++, "ta3", "ta3@uni.edu"));

    // Buildings and Rooms
    BuildingRepository bRepo("buildings.bin");
    bRepo.save({});
    RoomRepository rRepo("rooms.bin");
    rRepo.save({});
    int bid = bRepo.getNextId();
    int rid = rRepo.getNextId();
    // Assign attendant user ID 5 (att_a) to building 1
    Building b1(bid++, "Engineering Block", 5, "North Campus");
    Building b2(bid++, "Science Block", -1, "East Campus");
    bRepo.add(b1); bRepo.add(b2);

    Room r1(rid++, b1.getId(), "E101", 30, "Lab");
    Room r2(rid++, b1.getId(), "E102", 25, "Lab");
    Room r3(rid++, b2.getId(), "S201", 40, "Lecture");
    rRepo.add(r1); rRepo.add(r2); rRepo.add(r3);

    // Assign rooms to buildings by re-saving the buildings vector
    b1.addRoom(r1.getId()); b1.addRoom(r2.getId());
    b2.addRoom(r3.getId());
    auto buildings = bRepo.getAll();
    // replace created buildings in the vector (they were added earlier by add)
    for (auto &bb : buildings) {
        if (bb.getId() == b1.getId()) bb = b1;
        else if (bb.getId() == b2.getId()) bb = b2;
    }
    bRepo.save(buildings);

    // Labs
    LabRepository labRepo("labs.bin");
    labRepo.saveLabs({});
    int lid = labRepo.getNextId();
    ScheduleTiming s1("Monday", "09:00", "11:00");
    // Assign to instructor user ID 3 (instr_a)
    Lab lab1(lid++, "CS1001", "A", r1.getId(), b1.getId(), 3, s1);
    ScheduleTiming s2("Wednesday", "14:00", "16:00");
    Lab lab2(lid++, "CS2001", "B", r2.getId(), b1.getId(), 3, s2);
    ScheduleTiming s3("Friday", "10:00", "12:00");
    Lab lab3(lid++, "CS3001", "C", r3.getId(), b2.getId(), 3, s3);
    labRepo.add(lab1); labRepo.add(lab2); labRepo.add(lab3);

    // Actual timings
    ActualTimingRepository tRepo("actual_timings.bin");
    // add a few sample timings
    tRepo.add(ActualTiming(lab1.getId(), 3, "2025-11-01", "09:05", "11:00", 1.92, "OK"));
    tRepo.add(ActualTiming(lab2.getId(), 3, "2025-11-03", "14:00", "16:10", 2.17, "Late finish"));

    // Makeup requests
    MakeupRequestRepository mRepo("makeup_requests.bin");
    int mid = mRepo.getNextId();
    mRepo.add(MakeupRequest(mid++, lab1.getId(), 3, "2025-12-01", "09:00", "11:00", "pending"));

    std::cout << "Seeded users, instructors, TAs, buildings, rooms, labs, timings, and makeup requests.\n";
    return 0;
}
