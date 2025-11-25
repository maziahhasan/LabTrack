#pragma once
#include <string>

class MakeupRequest {
private:
    int id;
    int labId;
    int instructorId; // instructor who requested
    int roomId; // room for makeup session
    std::string date; // YYYY-MM-DD
    std::string time; // HH:mm-HH:mm
    std::string reason;
    std::string status; // Pending, Approved, Rejected
public:
    MakeupRequest() = default;
    MakeupRequest(int id, int labId, int instructorId, int roomId, const std::string &date, const std::string &time, const std::string &reason, const std::string &status = "Pending")
        : id(id), labId(labId), instructorId(instructorId), roomId(roomId), date(date), time(time), reason(reason), status(status) {}

    int getId() const { return id; }
    int getLabId() const { return labId; }
    int getInstructorId() const { return instructorId; }
    int getRoomId() const { return roomId; }
    std::string getDate() const { return date; }
    std::string getTime() const { return time; }
    std::string getReason() const { return reason; }
    std::string getStatus() const { return status; }

    void setStatus(const std::string &s) { status = s; }
};
