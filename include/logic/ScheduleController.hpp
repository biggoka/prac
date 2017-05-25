#pragma once

#include <memory>
#include <list>

#include "Schedule.hpp"
#include "InfoBank.hpp"
class Request;
 

class ScheduleController {
    std::list<std::shared_ptr<Request>> requests;

    bool recursive_try(std::list<std::shared_ptr<Request>>::iterator start,
        std::list<std::shared_ptr<Request>>::iterator end, int, int);

    std::shared_ptr<InfoBank> bank;

public:
    Schedule schedule;
    void add_request(std::shared_ptr<Request> request);
    void remove_request(std::shared_ptr<Request> request);

    bool generate_schedule(std::shared_ptr<InfoBank> bank);
    void print();
};