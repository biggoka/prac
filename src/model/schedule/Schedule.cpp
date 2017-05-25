#include "Schedule.hpp"

#include "ScheduleCell.hpp"
#include "ScheduleCellEntry.hpp"
#include "ScheduleTime.hpp"
#include "Constants.hpp"

#include <iostream>

Schedule::Schedule() {
    for (int i = 0; i < Constants::DAYS_IN_WEEK; i++) {
        for (int j = 0; j < Constants::LECTURES_IN_DAY; j++) {
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

void Schedule::print() {
    for (int i = 0; i < Constants::DAYS_IN_WEEK; i++) {
        std::cout << "" << std::endl;
        std::cout << "*******************************" << std::endl;
        std::cout << "***  Day of Week: " << i + 1 << std::endl;
        std::cout << "*******************************" << std::endl;

        for (int j = 0; j < Constants::LECTURES_IN_DAY; j++) {
            std::cout << "### Lecture Number: " << j + 1 << std::endl;
            // std::cout << "" << std::endl;
            
            for (auto &entry: cells[i][j]->entries){
                std::cout << "group: " << entry->group_id << "; ";
                std::cout << "subject: " << entry->subject << "; ";
                std::cout << "professor: " << entry->professor << "; ";
                std::cout << "room: " << entry->room_id << "; " << std::endl;
                // std::cout << "" << std::endl;
                
            }

            // std::cout << "" << std::endl;
        }


        // std::cout << "" << std::endl;
    }
}