#pragma once

#include <memory>

class GroupSchedule {
    size_t group;

    std::shared_ptr<GroupScheduleCell>[7][7];

}