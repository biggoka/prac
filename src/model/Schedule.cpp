#include "Schedule.hpp"

#include "ScheduleCell.hpp"
#include "ScheduleCellEntry.hpp"
#include "ScheduleTime.hpp"

#include <iostream>

Schedule::Schedule() {
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            cells[i][j] = std::make_shared<ScheduleCell>();
        }
    }
}

bool Schedule::add_entry(std::shared_ptr<ScheduleCellEntry> entry, std::shared_ptr<ScheduleTime> time) {
    // std::cout << "schedule: adding entry to cell " << time->get_day_of_week() << " " << time->get_lecture_number() << std::endl;
    return cells[time->get_day_of_week()-1][time->get_lecture_number()-1]->add_entry(entry);
}

void Schedule::remove_entry(std::shared_ptr<ScheduleCellEntry> entry, std::shared_ptr<ScheduleTime> time) {
    // std::cout << "schedule: removing entry to cell " << time->get_day_of_week() << " " << time->get_lecture_number() << std::endl;
    cells[time->get_day_of_week()-1][time->get_lecture_number()-1]->remove_entry(entry);
}