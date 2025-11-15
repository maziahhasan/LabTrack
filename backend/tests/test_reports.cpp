#include <iostream>
#include "../repositories/LabRepository.h"
#include "../services/ReportService.h"

int main() {
    LabRepository repo("test_labs.bin");
    ReportService rs(repo);

    // print weekly schedule
    auto schedule = rs.weeklySchedule();
    std::cout << "Weekly schedule count: " << schedule.size() << std::endl;
    for (const Lab &l : schedule) {
        std::cout << l.getCourseCode() << " " << l.getSection() << " on " << l.getSchedule().getDay()
            << " " << l.getSchedule().getStart() << "-" << l.getSchedule().getEnd() << std::endl;
    }

    // pick first lab id
    if (!schedule.empty()) {
        int id = schedule[0].getId();
        TimeSheetSummary sum = rs.computeTimeSheetSummary(id, "2025-01-01", "2025-12-31");
        std::cout << "Lab " << id << " totalHours=" << sum.totalHours << " leaves=" << sum.leaves << std::endl;
    }

    return 0;
}
