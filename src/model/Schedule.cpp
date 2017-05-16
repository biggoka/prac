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