#pragma once

#include "Predicate.hpp"
#include "Constants.hpp"

#include <memory>
#include <set>

class RequestCase {
public:
    std::shared_ptr<Predicate> predicate;

    std::set<int> rooms;
    bool days[Constants::DAYS_IN_WEEK][Constants::LECTURES_IN_DAY];

    int time_options_count;
    int room_options_count;

    bool day_is_set(int i, int j);

    RequestCase();

    bool operator==(const RequestCase &) const;
};