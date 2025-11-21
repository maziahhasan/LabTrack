#include "HODRepository.h"
#include <fstream>

HODRepository::HODRepository(const std::string &file) { fileName = file; }

void HODRepository::save(const std::vector<HOD> &v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (auto &h : v) {
        int id = h.getId(); out.write((char*)&id, sizeof(id));
        int len = h.getName().size(); out.write((char*)&len, sizeof(len)); out.write(h.getName().c_str(), len);
        int dlen = h.getDepartment().size(); out.write((char*)&dlen, sizeof(dlen)); out.write(h.getDepartment().c_str(), dlen);
    }
}

std::vector<HOD> HODRepository::load() {
    std::vector<HOD> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        int len; in.read((char*)&len, sizeof(len)); char *buf = new char[len+1]; in.read(buf, len); buf[len]='\0'; std::string name(buf); delete[] buf;
        int dlen; in.read((char*)&dlen, sizeof(dlen)); char *db = new char[dlen+1]; in.read(db, dlen); db[dlen]='\0'; std::string dept(db); delete[] db;
        outv.push_back(HOD(id, name, dept));
    }
    return outv;
}

int HODRepository::getNextId() { auto v = load(); int maxId = 0; for (auto &h : v) if (h.getId() > maxId) maxId = h.getId(); return maxId + 1; }

void HODRepository::add(const HOD &h) { auto v = load(); v.push_back(h); save(v); }

std::vector<HOD> HODRepository::getAll() { return load(); }
