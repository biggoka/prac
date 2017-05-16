#include "ScheduleTime.hpp"
//#include "Constants.hpp"

#include <iostream>
#include <stdexcept>


ScheduleTime::ScheduleTime(int day, int number) {
    if (day < 1 or day > 7 or number < 1 or number > 7) {
        std::cerr << "wrong day or week in ScheduleTime::ScheduleTime " << std::endl;
        throw std::invalid_argument("bad day or number in ScheduleTime");
    }

    day_of_week = day;
    lecture_number = number;
}

int ScheduleTime::get_day_of_week() const {
    return day_of_week;
}

int ScheduleTime::get_lecture_number() const {
    return lecture_number;
}