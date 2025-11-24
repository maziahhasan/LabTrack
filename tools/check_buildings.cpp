#include <iostream>
#include "../backend/repositories/BuildingRepository.h"
#include "../backend/repositories/LabRepository.h"

int main() {
    BuildingRepository bRepo("buildings.bin");
    LabRepository lRepo("labs.bin");
    
    auto buildings = bRepo.getAll();
    std::cout << "Buildings:\n";
    for (const auto& b : buildings) {
        std::cout << "  ID:" << b.getId() 
                  << " Name:" << b.getName()
                  << " AttendantID:" << b.getAttendantId() << "\n";
    }
    
    auto labs = lRepo.getAllLabs();
    std::cout << "\nLabs:\n";
    for (const auto& l : labs) {
        std::cout << "  ID:" << l.getId()
                  << " Name:" << l.getName()
                  << " BuildingID:" << l.getBuildingId() << "\n";
    }
    
    return 0;
}
