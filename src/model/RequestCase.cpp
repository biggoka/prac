#include "RequestCase.hpp"

#include "Constants.hpp"

#include <memory>

RequestCase::RequestCase() {
    predicate.reset();
    for (int i = 0; i < Constants::DAYS_IN_WEEK; i++) {
        for (int j = 0; j < Constants::LECTURES_IN_DAY; j++) {
            days[i][j] = false;
        }
    }
    time_options_count = 0;
    room_options_count = 0;
}

bool RequestCase::operator==(const RequestCase &c) const {
    if (rooms != c.rooms) {
        return false;
    }

    if (time_options_count != c.time_options_count or room_options_count != c.room_options_count) {
        return false;
    }

    for (int i = 0; i < Constants::DAYS_IN_WEEK; i++) {
        for (int j = 0; j < Constants::LECTURES_IN_DAY; j++) {
            if (days[i][j] != c.days[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool RequestCase::day_is_set(int i, int j) {
    return days[i-1][j-1];
}