#include "AcademicOfficerRepository.h"
#include <fstream>

AcademicOfficerRepository::AcademicOfficerRepository(const std::string &file) { fileName = file; }

void AcademicOfficerRepository::save(const std::vector<AcademicOfficer> &v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (auto &a : v) {
        int id = a.getId(); out.write((char*)&id, sizeof(id));
        int len = a.getName().size(); out.write((char*)&len, sizeof(len)); out.write(a.getName().c_str(), len);
    }
}

std::vector<AcademicOfficer> AcademicOfficerRepository::load() {
    std::vector<AcademicOfficer> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        int len; in.read((char*)&len, sizeof(len)); char *buf = new char[len+1]; in.read(buf, len); buf[len]='\0'; std::string name(buf); delete[] buf;
        outv.push_back(AcademicOfficer(id, name));
    }
    return outv;
}

int AcademicOfficerRepository::getNextId() { auto v = load(); int maxId = 0; for (auto &a : v) if (a.getId() > maxId) maxId = a.getId(); return maxId + 1; }

void AcademicOfficerRepository::add(const AcademicOfficer &a) { auto v = load(); v.push_back(a); save(v); }

std::vector<AcademicOfficer> AcademicOfficerRepository::getAll() { return load(); }
