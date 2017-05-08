#pragma once

#include <string>
#include <vector>

class Request {
public:
    std::string professor_name;
    std::string subject;

    bool days[7][7]; // 7 days in a week by 7 pairs in a day; first is day in a week

    size_t group_id;
    size_t room_id;

    Request();

    void set_day(short week_day, short pair_number, bool is);
    bool day_is_set(short week_day, short pair_number) const;
};