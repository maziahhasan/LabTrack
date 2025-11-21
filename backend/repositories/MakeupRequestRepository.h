#pragma once
#include <vector>
#include <string>
#include "../models/MakeupRequest.h"

class MakeupRequestRepository {
private:
    std::string fileName;
public:
    MakeupRequestRepository(const std::string &file = "makeup_requests.bin");
    void save(const std::vector<MakeupRequest> &v);
    std::vector<MakeupRequest> load();
    int getNextId();
    void add(const MakeupRequest &m);
    void update(const MakeupRequest &m);
};
