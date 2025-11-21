#include "MakeupRequestRepository.h"
#include <fstream>

MakeupRequestRepository::MakeupRequestRepository(const std::string &file) : fileName(file) {}

void MakeupRequestRepository::save(const std::vector<MakeupRequest> &v) {
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    int size = v.size(); out.write((char*)&size, sizeof(size));
    for (const auto &m : v) {
        out.write((char*)&m.getId(), sizeof(int));
        out.write((char*)&m.getLabId(), sizeof(int));
        out.write((char*)&m.getRequestedBy(), sizeof(int));
        int len = m.getDate().size(); out.write((char*)&len, sizeof(len)); out.write(m.getDate().c_str(), len);
        len = m.getStart().size(); out.write((char*)&len, sizeof(len)); out.write(m.getStart().c_str(), len);
        len = m.getEnd().size(); out.write((char*)&len, sizeof(len)); out.write(m.getEnd().c_str(), len);
        len = m.getStatus().size(); out.write((char*)&len, sizeof(len)); out.write(m.getStatus().c_str(), len);
    }
}

std::vector<MakeupRequest> MakeupRequestRepository::load() {
    std::vector<MakeupRequest> outv;
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return outv;
    int size; in.read((char*)&size, sizeof(size));
    for (int i = 0; i < size; ++i) {
        int id; in.read((char*)&id, sizeof(id));
        int labId; in.read((char*)&labId, sizeof(labId));
        int reqBy; in.read((char*)&reqBy, sizeof(reqBy));
        int len; in.read((char*)&len, sizeof(len)); char *buf = new char[len+1]; in.read(buf, len); buf[len]='\0'; std::string date(buf); delete[] buf;
        in.read((char*)&len, sizeof(len)); buf = new char[len+1]; in.read(buf, len); buf[len]='\0'; std::string start(buf); delete[] buf;
        in.read((char*)&len, sizeof(len)); buf = new char[len+1]; in.read(buf, len); buf[len]='\0'; std::string end(buf); delete[] buf;
        in.read((char*)&len, sizeof(len)); buf = new char[len+1]; in.read(buf, len); buf[len]='\0'; std::string status(buf); delete[] buf;
        outv.push_back(MakeupRequest(id, labId, reqBy, date, start, end, status));
    }
    return outv;
}

int MakeupRequestRepository::getNextId() {
    auto v = load(); int maxId = 0; for (auto &m : v) if (m.getId() > maxId) maxId = m.getId(); return maxId + 1;
}

void MakeupRequestRepository::add(const MakeupRequest &m) { auto v = load(); v.push_back(m); save(v); }

void MakeupRequestRepository::update(const MakeupRequest &m) {
    auto v = load();
    for (auto &it : v) {
        if (it.getId() == m.getId()) {
            it = m;
            break;
        }
    }
    save(v);
}
