#include "ScheduleController.hpp"

#include <memory>
#include <list>
#include <string>
#include <iostream>

#include "Request.hpp"
#include "Schedule.hpp"
#include "ScheduleCellEntry.hpp"
#include "ScheduleTime.hpp"

#include "Constants.hpp"

void ScheduleController::add_request(std::shared_ptr<Request> request) {
    requests.push_back(request);
}

void ScheduleController::remove_request(std::shared_ptr<Request> request) {
    for (auto it = requests.begin(); it != requests.end(); it++) {
        if (*(*it) == *request) {
            requests.erase(it);
            return;
        }
    }
}

void ScheduleController::print() {
    schedule.print();
}

bool ScheduleController::recursive_try(std::list<std::shared_ptr<Request>>::iterator start,
    std::list<std::shared_ptr<Request>>::iterator end, int current, int depth) 
{
    if (start == end) {
        return true;
    }

    auto request = (*start);

    int group_id = request->group_id;
    std::string professor(request->professor);
    std::string subject(request->subject);
    auto &cases = request->cases;

    if (cases.size() == 0) {
        return false;
    }

    if (!bank->contains_group(group_id)) {
        return false;
    }
    if (!bank->contains_subject(subject)) {
        return false;
    }

    std::shared_ptr<ScheduleCellEntry> entry = std::make_shared<ScheduleCellEntry>(group_id, 0, professor, subject);

    for (auto &case_: cases) {
        for (auto &room: case_->rooms) {
            entry->room_id = room;
            for (int i = 1; i <= Constants::DAYS_IN_WEEK; i++) {
                for (int j = 1; j <= Constants::LECTURES_IN_DAY; j++) {
                    if (case_->day_is_set(i, j)) {

                        std::shared_ptr<ScheduleTime> time = std::make_shared<ScheduleTime>(i, j);

                        if (schedule.add_entry(entry, time)) {

                            start++;
                            if (recursive_try(start, end, current + 1, depth)) {
                                return true;
                            } else {
                                start--;
                                schedule.remove_entry(entry, time);
                            }
                            
                        }

                    }
                }
            }

        }
    }
    return false;
}

bool ScheduleController::generate_schedule(std::shared_ptr<InfoBank> bank_) {
    bank = bank_;

    if (requests.size() == 0) {
        return true;
    }

    return recursive_try(requests.begin(), requests.end(), 1, requests.size());
}









// public:
//     void add_request(std::shared_ptr<Request> request);
//     void remove_request(std::shared_ptr<Request> request);

//     bool generate_schedule();
// };