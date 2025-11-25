#include "ActualTimingRepository.h"
#include <fstream>
#include <algorithm>

static void writeString(std::ofstream &out, const std::string &s) {
    int len = (int)s.length();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len);
}

static std::string readString(std::ifstream &in) {
    int len = 0;
    in.read((char*)&len, sizeof(len));
    if (!in) return std::string();
    if (len < 0) return std::string();
    char *buf = new char[len + 1];
    in.read(buf, len);
    buf[len] = '\0';
    std::string s(buf);
    delete[] buf;
    return s;
}

ActualTimingRepository::ActualTimingRepository(const std::string &file) : fileName(file) {}

std::vector<ActualTiming> ActualTimingRepository::getAllActualTimings() {
    std::vector<ActualTiming> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int count = 0;
    in.read((char*)&count, sizeof(count));
    if (!in) return outv;
    for (int i = 0; i < count; ++i) {
        int labId = -1; in.read((char*)&labId, sizeof(labId));
        int taId = -1; in.read((char*)&taId, sizeof(taId));
        std::string date = readString(in);
        std::string start = readString(in);
        std::string end = readString(in);
        double duration = 0.0; in.read((char*)&duration, sizeof(duration));
        std::string notes = readString(in);
        outv.emplace_back(labId, taId, date, start, end, duration, notes);
    }
    return outv;
}

std::vector<ActualTiming> ActualTimingRepository::getActualTimingsByLabId(int labId) {
    auto all = getAllActualTimings();
    std::vector<ActualTiming> res;
    std::copy_if(all.begin(), all.end(), std::back_inserter(res), [labId](const ActualTiming &a){ return a.getLabId() == labId; });
    return res;
}

std::vector<ActualTiming> ActualTimingRepository::getActualTimingsByTAId(int taId) {
    auto all = getAllActualTimings();
    std::vector<ActualTiming> res;
    std::copy_if(all.begin(), all.end(), std::back_inserter(res), [taId](const ActualTiming &a){ return a.getTaId() == taId; });
    return res;
}

std::vector<ActualTiming> ActualTimingRepository::getActualTimingsByDate(const std::string &date) {
    auto all = getAllActualTimings();
    std::vector<ActualTiming> res;
    std::copy_if(all.begin(), all.end(), std::back_inserter(res), [&date](const ActualTiming &a){ return a.getDate() == date; });
    return res;
}

void ActualTimingRepository::add(const ActualTiming &timing) {
    auto all = getAllActualTimings();
    all.push_back(timing);
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int count = (int)all.size();
    out.write((char*)&count, sizeof(count));
    for (const auto &a : all) {
        int lid = a.getLabId(); out.write((char*)&lid, sizeof(lid));
        int tid = a.getTaId(); out.write((char*)&tid, sizeof(tid));
        writeString(out, a.getDate());
        writeString(out, a.getStartTime());
        writeString(out, a.getEndTime());
        double dur = a.getDuration(); out.write((char*)&dur, sizeof(dur));
        writeString(out, a.getNotes());
    }
}

bool ActualTimingRepository::update(const ActualTiming &timing) {
    auto all = getAllActualTimings();
    bool found = false;
    for (auto &a : all) {
        // match by labId + date + startTime as a simple unique key
        if (a.getLabId() == timing.getLabId() && a.getDate() == timing.getDate() && a.getStartTime() == timing.getStartTime()) {
            a = timing; found = true; break;
        }
    }
    if (found) {
        std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
        int count = (int)all.size(); out.write((char*)&count, sizeof(count));
        for (const auto &a : all) {
            int lid = a.getLabId(); out.write((char*)&lid, sizeof(lid));
            int tid = a.getTaId(); out.write((char*)&tid, sizeof(tid));
            writeString(out, a.getDate());
            writeString(out, a.getStartTime());
            writeString(out, a.getEndTime());
            double dur = a.getDuration(); out.write((char*)&dur, sizeof(dur));
            writeString(out, a.getNotes());
        }
    }
    return found;
}

bool ActualTimingRepository::remove(int labId, const std::string& date) {
    auto all = getAllActualTimings();
    auto it = std::remove_if(all.begin(), all.end(), 
        [labId, &date](const ActualTiming& t) { 
            return t.getLabId() == labId && t.getDate() == date; 
        });
    if (it != all.end()) {
        all.erase(it, all.end());
        std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
        int count = (int)all.size(); out.write((char*)&count, sizeof(count));
        for (const auto &a : all) {
            int lid = a.getLabId(); out.write((char*)&lid, sizeof(lid));
            int tid = a.getTaId(); out.write((char*)&tid, sizeof(tid));
            writeString(out, a.getDate());
            writeString(out, a.getStartTime());
            writeString(out, a.getEndTime());
            double dur = a.getDuration(); out.write((char*)&dur, sizeof(dur));
            writeString(out, a.getNotes());
        }
        return true;
    }
    return false;
}

bool ActualTimingRepository::removeByLabId(int labId) {
    auto all = getAllActualTimings();
    auto it = std::remove_if(all.begin(), all.end(), 
        [labId](const ActualTiming& t) { return t.getLabId() == labId; });
    if (it != all.end()) {
        all.erase(it, all.end());
        std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
        int count = (int)all.size(); out.write((char*)&count, sizeof(count));
        for (const auto &a : all) {
            int lid = a.getLabId(); out.write((char*)&lid, sizeof(lid));
            int tid = a.getTaId(); out.write((char*)&tid, sizeof(tid));
            writeString(out, a.getDate());
            writeString(out, a.getStartTime());
            writeString(out, a.getEndTime());
            double dur = a.getDuration(); out.write((char*)&dur, sizeof(dur));
            writeString(out, a.getNotes());
        }
        return true;
    }
    return false;
}
