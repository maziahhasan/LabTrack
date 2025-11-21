#include "TARepository.h"
#include <fstream>

TARepository::TARepository(const std::string &file) { fileName = file; }

void TARepository::save(const std::vector<TA>& v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (auto &ta : v) {
        int id = ta.getId(); out.write((char*)&id, sizeof(id));
        int len = ta.getName().size(); out.write((char*)&len, sizeof(len));
        out.write(ta.getName().c_str(), len);
    }
}

std::vector<TA> TARepository::load() {
    std::vector<TA> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        int len; in.read((char*)&len, sizeof(len));
        char *buf = new char[len+1]; in.read(buf, len); buf[len]='\0';
        std::string name(buf); delete[] buf;
        outv.push_back(TA(id, name));
    }
    return outv;
}

int TARepository::getNextId() { auto v = load(); int maxId = 0; for (auto &t : v) if (t.getId() > maxId) maxId = t.getId(); return maxId + 1; }

void TARepository::add(const TA &ta) { auto v = load(); v.push_back(ta); save(v); }

std::vector<TA> TARepository::getAll() { return load(); }
