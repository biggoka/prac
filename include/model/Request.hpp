#pragma once

#include <string>
#include <vector>

#include "Constants.hpp"

class Request {
public:
    std::string professor;
    std::string subject;

    bool days[Constants::DAYS_IN_WEEK][Constants::LECTURES_IN_DAY]; // 7 days in a week by 7 pairs in a day; first is day in a week

    int group_id;
    int room_id;

    Request();

    void set_day(int week_day, int pair_number, bool is);
    bool day_is_set(int week_day, int pair_number) const;

    bool operator==(const Request &r) const;
};