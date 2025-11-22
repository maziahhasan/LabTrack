#include "InstructorRepository.h"
#include <algorithm>

static void writeString(std::ofstream &out, const std::string &s) {
    int len = s.length();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len);
}
static std::string readString(std::ifstream &in) {
    int len; in.read((char*)&len, sizeof(len));
    char *buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    std::string s(buffer);
    delete[] buffer; return s;
}

InstructorRepository::InstructorRepository(const std::string &file) { fileName = file; }

void InstructorRepository::save(const std::vector<Instructor>& v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (auto &ins : v) {
        int id = ins.getId(); out.write((char*)&id, sizeof(id));
        writeString(out, ins.getName());
    }
}

std::vector<Instructor> InstructorRepository::load() {
    std::vector<Instructor> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        std::string name = readString(in);
        outv.push_back(Instructor(id, name));
    }
    return outv;
}

int InstructorRepository::getNextId() {
    auto v = load(); int maxId = 0; for (auto &i : v) if (i.getId() > maxId) maxId = i.getId(); return maxId + 1;
}

void InstructorRepository::add(const Instructor &ins) { auto v = load(); v.push_back(ins); save(v); }

std::vector<Instructor> InstructorRepository::getAll() { return load(); }

bool InstructorRepository::update(const Instructor& ins) {
    std::vector<Instructor> instructors = load();
    bool found = false;
    for (auto& instructor : instructors) {
        if (instructor.getId() == ins.getId()) {
            instructor = ins;
            found = true;
            break;
        }
    }
    if (found) {
        save(instructors);
    }
    return found;
}

