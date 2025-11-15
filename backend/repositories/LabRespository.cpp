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
    char *buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    string s(buffer);
    delete[] buffer;
    return s;
}

LabRepository::LabRepository(const string &file) {
    fileName = file;
}

// Return all labs (wrapper)
vector<Lab> LabRepository::getAll() {
    return loadLabs();
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

        int inst = lab.getInstructorId();
        out.write((char*)&inst, sizeof(int));

        // schedule
        ScheduleTiming sch = lab.getSchedule();
        writeString(out, sch.getDay());
        writeString(out, sch.getStart());
        writeString(out, sch.getEnd());

        // TAs
        const vector<TA> &tas = lab.getTAs();
        int taCount = tas.size();
        out.write((char*)&taCount, sizeof(int));

        for (const TA &ta : tas) {
            int tid = ta.getId();
            out.write((char*)&tid, sizeof(int));
            writeString(out, ta.getName());
        }

        // Actual timings
        const vector<ActualTiming> &times = lab.getTimeSheets();
        int tsCount = times.size();
        out.write((char*)&tsCount, sizeof(int));

        for (const ActualTiming &t : times) {
            writeString(out, t.getDate());
            writeString(out, t.getStart());
            writeString(out, t.getEnd());
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

    for (int i = 0; i < size; i++) {
        int id;
        in.read((char*)&id, sizeof(int));

        string courseCode = readString(in);
        string section = readString(in);

        Lab lab(id, courseCode, section);

        int inst;
        in.read((char*)&inst, sizeof(int));
        lab.setInstructorId(inst);

        // schedule
        string day = readString(in);
        string start = readString(in);
        string end = readString(in);
        lab.setSchedule(ScheduleTiming(day, start, end));

        // TAs
        int taCount;
        in.read((char*)&taCount, sizeof(int));

        for (int j = 0; j < taCount; j++) {
            int tid;
            in.read((char*)&tid, sizeof(int));
            string tname = readString(in);
            lab.addTA(TA(tid, tname));
        }

        // Actual timings
        int tsCount;
        in.read((char*)&tsCount, sizeof(int));

        for (int k = 0; k < tsCount; k++) {
            string d = readString(in);
            string s = readString(in);
            string e = readString(in);
            lab.addActualTiming(ActualTiming(d, s, e));
        }

        labs.push_back(lab);
    }

    in.close();
    return labs;
}
