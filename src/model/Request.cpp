#include "Request.hpp"

#include <stdexcept>

Request::Request() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            days[i][j] = false;
        }
    }
}

void Request::set_day(short week_day, short pair_number, bool is) {
    if (week_day > 7 or week_day < 1 or pair_number > 7 or pair_number < 1) {
        throw std::invalid_argument("wrong argument in Request::set_day");
    }
    days[week_day - 1][pair_number - 1] = is;
}

bool Request::day_is_set(short week_day, short pair_number) const {
    if (week_day > 7 or week_day < 1 or pair_number > 7 or pair_number < 1) {
        throw std::invalid_argument("wrong argument in Request::set_day");
    }

    return days[week_day - 1][pair_number - 1];
}