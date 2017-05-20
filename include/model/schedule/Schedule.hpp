#pragma once 

#include <memory>

#include "Constants.hpp"

class ScheduleCell;
class ScheduleCellEntry;
class ScheduleTime;

class Schedule {

    std::shared_ptr<ScheduleCell> cells[Constants::DAYS_IN_WEEK][Constants::LECTURES_IN_DAY];

public:
    Schedule();

    bool add_entry(std::shared_ptr<ScheduleCellEntry> entry, std::shared_ptr<ScheduleTime> time);

    void remove_entry(std::shared_ptr<ScheduleCellEntry> entry, std::shared_ptr<ScheduleTime> time);
};