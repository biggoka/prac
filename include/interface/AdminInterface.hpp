#pragma once

#include "Interface.hpp"
#include "ScheduleController.hpp"

#include <string>

class AdminInterface : public Interface {

    ScheduleController schedule_controller;

public:
    void add_room();
    void add_subject();
    void add_group();

    void clear_rooms();
    void clear_subjects();
    void clear_groups();
    void clear_requests();

    void generate_schedule();

    void start();
    void exit();
};