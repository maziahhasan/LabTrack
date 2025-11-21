#pragma once
#include <string>
#include <ctime>
#include <algorithm>

namespace DateUtils {

// parse YYYY-MM-DD to time_t (UTC: local timezone adjusted)
inline time_t parseDate(const std::string &date) {
    std::tm tm{};
    sscanf_s(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900; tm.tm_mon -= 1; tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0; tm.tm_isdst = -1;
    return mktime(&tm);
}

// day name e.g. Monday-> lowercase
inline std::string normalizeDay(const std::string &d) {
    std::string s = d; std::transform(s.begin(), s.end(), s.begin(), ::tolower); return s;
}

inline std::string dayOfWeek(time_t t) {
    std::tm *tm = std::localtime(&t);
    static const char *names[7] = {"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
    return std::string(names[tm->tm_wday]);
}

inline double hoursBetween(const std::string &start, const std::string &end) {
    // start/end format hh:mm
    int sh, sm, eh, em; sh = sm = eh = em = 0;
    sscanf_s(start.c_str(), "%d:%d", &sh, &sm);
    sscanf_s(end.c_str(), "%d:%d", &eh, &em);
    int ssec = sh*3600 + sm*60; int esec = eh*3600 + em*60;
    return (double)(esec - ssec) / 3600.0;
}

}
