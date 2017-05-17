#include "Schedule.hpp"

#include "ScheduleCell.hpp"
#include "ScheduleCellEntry.hpp"
#include "ScheduleTime.hpp"

Schedule::Schedule() {
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            cells[i][j] = std::make_shared<ScheduleCell>();
        }
    }
}

bool Schedule::add_entry(std::shared_ptr<ScheduleCellEntry> entry, std::shared_ptr<ScheduleTime> time) {
    return cells[time->get_day_of_week()][time->get_lecture_number()]->add_entry(entry);
}

void Schedule::remove_entry(std::shared_ptr<ScheduleCellEntry> entry, std::shared_ptr<ScheduleTime> time) {
    cells[time->get_day_of_week()][time->get_lecture_number()]->remove_entry(entry);
}