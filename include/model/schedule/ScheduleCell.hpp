#pragma once

#include <list>
#include <set>
#include <string>
#include <memory>

class ScheduleCellEntry;

class ScheduleCell {


    std::set<int> groups;
    std::set<int> rooms;
    std::set<std::string> professors;

public:
    std::list<std::shared_ptr<ScheduleCellEntry>> entries;

    bool add_entry(std::shared_ptr<ScheduleCellEntry> entry);
    bool remove_entry(std::shared_ptr<ScheduleCellEntry> entry);

};