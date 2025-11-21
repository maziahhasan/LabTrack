#pragma once
#include <string>

class MakeupRequest {
private:
    int id;
    int labId;
    int requestedBy; // user id
    std::string date; // YYYY-MM-DD
    std::string start;
    std::string end;
    std::string status; // pending, approved, rejected
public:
    MakeupRequest() = default;
    MakeupRequest(int id, int labId, int requestedBy, const std::string &date, const std::string &start, const std::string &end, const std::string &status = "pending")
        : id(id), labId(labId), requestedBy(requestedBy), date(date), start(start), end(end), status(status) {}

    int getId() const { return id; }
    int getLabId() const { return labId; }
    int getRequestedBy() const { return requestedBy; }
    std::string getDate() const { return date; }
    std::string getStart() const { return start; }
    std::string getEnd() const { return end; }
    std::string getStatus() const { return status; }

    void setStatus(const std::string &s) { status = s; }
};
