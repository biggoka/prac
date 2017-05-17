#include "ScheduleController.hpp"

#include <memory>
#include <list>

#include "Request.hpp"
#include "Schedule.hpp"

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

bool ScheduleController::recursive_try(std::shared_ptr<Request> request, std::shared_ptr<Request> next_request) {
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (request->day_is_set(i, j)) {

                //

            }
        }
    }
}

bool ScheduleController::generate_schedule() {

}









// public:
//     void add_request(std::shared_ptr<Request> request);
//     void remove_request(std::shared_ptr<Request> request);

//     bool generate_schedule();
// };