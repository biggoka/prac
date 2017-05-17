#include "ScheduleCell.hpp"

#include "ScheduleCellEntry.hpp"

#include <memory>

bool ScheduleCell::add_entry(std::shared_ptr<ScheduleCellEntry> entry) {
    if (groups.find(entry->group_id) != groups.end() or \
        rooms.find(entry->room_id) != rooms.end() or \
        professors.find(entry->professor) != professors.end()) {
        return false;
    }

    groups.insert(entry->group_id);
    rooms.insert(entry->room_id);
    professors.insert(entry->professor);

    entries.push_back(entry);
    return true;
}

bool ScheduleCell::remove_entry(std::shared_ptr<ScheduleCellEntry> entry) {
    for (auto it = entries.begin(); it != entries.end(); it++) {
        if (*(*it) == *entry){
            entries.erase(it);

            if (auto it = groups.find(entry->group_id) != groups.end()) {
                groups.erase(it);
            }

            if (auto it = rooms.find(entry->room_id) != rooms.end()) {
                rooms.erase(it);
            }

            if (auto it = professors.find(entry->professor) != professors.end()) {
                professors.erase(entry->professor);
            }

            return true;
            break;
        }
    }
}













// class ScheduleCellEntry;

// class ScheduleCell {

//     std::list<std::shared_ptr<ScheduleCellEntry>> entries;

//     std::set<int> groups;
//     std::set<int> rooms;
//     std::set<std::string> professors;

// public:

//     bool add_entry(std::shared_ptr<ScheduleCellEntry> entry);
//     bool remove_entry(std::shared_ptr<ScheduleCellEntry> entry);

// };