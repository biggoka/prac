#pragma once

#include <memory>

class Schedule;

class ScheduleCell {
public:
    std::shared_ptr<Schedule> schedule;

    std::string subject;
    std::string professor_name;
    size_t group;
    size_t room;
}