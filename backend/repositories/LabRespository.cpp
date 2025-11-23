#include "LabRepository.h"
using namespace std;
#include <algorithm>

// write string
void LabRepository::writeString(ofstream &out, const string &s) {
    int len = s.length();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len);
}

// read string
string LabRepository::readString(ifstream &in) {
    int len;
    in.read((char*)&len, sizeof(len));
    if (!in) return string();

    // basic sanity checks to avoid huge allocations from corrupted files
    const int MAX_STR_LEN = 10 * 1000 * 1000; // 10MB
    if (len < 0 || len > MAX_STR_LEN) {
        in.setstate(std::ios::failbit);
        return string();
    }

    char *buffer = new char[len + 1];
    in.read(buffer, len);
    if (!in) {
        delete[] buffer;
        return string();
    }
    buffer[len] = '\0';
    string s(buffer);
    delete[] buffer;
    return s;
}

LabRepository::LabRepository(const string &file) {
    fileName = file;
}



// Find lab by id; if not found return a Lab with id = -1
Lab LabRepository::getById(int id) {
    vector<Lab> labs = loadLabs();
    for (const Lab &l : labs) {
        if (l.getId() == id) return l;
    }
    return Lab(-1, "", "");
}

void LabRepository::add(const Lab &lab) {
    vector<Lab> labs = loadLabs();
    labs.push_back(lab);
    saveLabs(labs);
}

bool LabRepository::update(const Lab &lab) {
    vector<Lab> labs = loadLabs();
    bool found = false;
    for (size_t i = 0; i < labs.size(); ++i) {
        if (labs[i].getId() == lab.getId()) {
            labs[i] = lab;
            found = true;
            break;
        }
    }
    if (found) saveLabs(labs);
    return found;
}

bool LabRepository::remove(int id) {
    vector<Lab> labs = loadLabs();
    auto it = std::remove_if(labs.begin(), labs.end(), [id](const Lab &l) { return l.getId() == id; });
    bool removed = it != labs.end();
    if (removed) {
        labs.erase(it, labs.end());
        saveLabs(labs);
    }
    return removed;
}

int LabRepository::getNextId() {
    vector<Lab> labs = loadLabs();
    int maxId = 0;
    for (const Lab &l : labs) {
        if (l.getId() > maxId) maxId = l.getId();
    }
    return maxId + 1;
}

void LabRepository::saveLabs(const vector<Lab> &labs) {
    ofstream out(fileName, ios::binary | ios::trunc);

    int size = labs.size();
    out.write((char*)&size, sizeof(size));

    for (const Lab &lab : labs) {

        int id = lab.getId();
        out.write((char*)&id, sizeof(int));

        writeString(out, lab.getCourseCode());
        writeString(out, lab.getSection());

        int room = lab.getRoomId();
        out.write((char*)&room, sizeof(int));

        int inst = lab.getInstructorId();
        out.write((char*)&inst, sizeof(int));

        // schedule
        ScheduleTiming sch = lab.getSchedule();
        writeString(out, sch.getDay());
        writeString(out, sch.getStart());
        writeString(out, sch.getEnd());

        // TAs
        const vector<int> &taIds = lab.getTAs();
        int taCount = taIds.size();
        out.write((char*)&taCount, sizeof(int));

        for (int taId : taIds) {
            out.write((char*)&taId, sizeof(int));
        }

        // Actual timings
        const vector<ActualTiming> &times = lab.getTimeSheets();
        int tsCount = times.size();
        out.write((char*)&tsCount, sizeof(int));

        for (const ActualTiming &t : times) {
            writeString(out, t.getDate());
            writeString(out, t.getStartTime());
            writeString(out, t.getEndTime());
        }
    }

    out.close();
}

vector<Lab> LabRepository::loadLabs() {
    vector<Lab> labs;

    ifstream in(fileName, ios::binary);
    if (!in.is_open()) return labs;

    int size;
    in.read((char*)&size, sizeof(size));
    if (!in) return labs;

    for (int i = 0; i < size; i++) {
        int id;
        in.read((char*)&id, sizeof(int));
        if (!in) break;

        string courseCode = readString(in);
        if (!in) break;
        string section = readString(in);
        if (!in) break;

        Lab lab(id, courseCode, section);

        int roomId;
        in.read((char*)&roomId, sizeof(int));
        if (!in) break;
        lab.setRoomId(roomId);

        int inst;
        in.read((char*)&inst, sizeof(int));
        if (!in) break;
        lab.setInstructorId(inst);

        // schedule
        string day = readString(in);
        if (!in) break;
        string start = readString(in);
        if (!in) break;
        string end = readString(in);
        if (!in) break;
        lab.setSchedule(ScheduleTiming(day, start, end));

        // TAs
        int taCount;
        in.read((char*)&taCount, sizeof(int));
        if (!in) break;

        for (int j = 0; j < taCount; j++) {
            int tid;
            in.read((char*)&tid, sizeof(int));
            if (!in) break;
            lab.addTA(tid);
        }

        // Actual timings
        int tsCount;
        in.read((char*)&tsCount, sizeof(int));
        if (!in) break;

        for (int k = 0; k < tsCount; k++) {
            string d = readString(in);
            if (!in) break;
            string s = readString(in);
            if (!in) break;
            string e = readString(in);
            if (!in) break;
            lab.addActualTiming(ActualTiming(d, s, e));
        }

        labs.push_back(lab);
    }

    in.close();
    return labs;
}

std::vector<Lab> LabRepository::getLabsByInstructorId(int instructorId) {
    std::vector<Lab> labs = loadLabs();
    std::vector<Lab> result;
    for (const auto& lab : labs) {
        if (lab.getInstructorId() == instructorId)
            result.push_back(lab);
    }
    return result;
}

std::vector<Lab> LabRepository::getLabsByBuildingId(int buildingId) {
    std::vector<Lab> labs = loadLabs();
    std::vector<Lab> result;
    for (const auto& lab : labs) {
        if (lab.getBuildingId() == buildingId)
            result.push_back(lab);
    }
    return result;
}

