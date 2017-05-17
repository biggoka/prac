#pragma once

#include <memory>
#include <list>

#include "Schedule.hpp"
class Request;


class ScheduleController {
    Schedule schedule;
    std::list<std::shared_ptr<Request>> requests;

    bool recursive_try(std::list<std::shared_ptr<Request>>::iterator start,
        std::list<std::shared_ptr<Request>>::iterator end);

public:
    void add_request(std::shared_ptr<Request> request);
    void remove_request(std::shared_ptr<Request> request);

    bool generate_schedule();
};