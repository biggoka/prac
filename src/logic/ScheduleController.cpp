#include "ScheduleController.hpp"

#include <memory>
#include <list>
#include <string>

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

bool ScheduleController::recursive_try(std::list<std::shared_ptr<Request>>::iterator start,
    std::list<std::shared_ptr<Request>>::iterator end) 
{
    if (start == end) {
        return true;
    }

    int group_id = (*start)->group_id;
    int room_id = (*start)->room_id;

    std::string professor((*start)->professor);
    std::string subject((*start)->subject);

    std::shared_ptr<ScheduleCellEntry> entry = std::make_shared<ScheduleCellEntry>(group_id, room_id, professor, subject);


    for (int i = 1; i <= Constants::DAYS_IN_WEEK; i++) {
        for (int j = 1; j <= Constants::LECTURES_IN_DAY; j++) {
            if ((*start)->day_is_set(i, j)) {

                std::shared_ptr<ScheduleTime> time = std::make_shared<ScheduleTime>(i, j);

                if (schedule.add_entry(entry, time)) {
                    // continue;

                    start++;
                    if (recursive_try(start, end)) {
                        return true;
                    } else {
                        start--;
                        schedule.remove_entry(entry, time);
                    }
                    
                }

            }
        }
    }

    return false;
}

bool ScheduleController::generate_schedule() {
    if (requests.size() == 0) {
        return true;
    }

    return recursive_try(requests.begin(), requests.end());
}









// public:
//     void add_request(std::shared_ptr<Request> request);
//     void remove_request(std::shared_ptr<Request> request);

//     bool generate_schedule();
// };