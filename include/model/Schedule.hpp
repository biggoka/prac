#pragma once 

#include <memory>

class ScheduleCell;
class ScheduleCellEntry;
class ScheduleTime;

class Schedule {

    std::shared_ptr<ScheduleCell> cells[7][7];

public:
    Schedule();

    bool add_entry(std::shared_ptr<ScheduleCellEntry> entry, ScheduleTime time);

    void remove_entry(std::shared_ptr<ScheduleCellEntry> entry, ScheduleTime time);
};