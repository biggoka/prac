#include "InfoBank.hpp"

void InfoBank::add_subject(const std::string &str) {
    std::string st(str);
    subjects.insert(st);
}

void InfoBank::add_group(const int group) {
    groups.insert(group);
}

void InfoBank::add_room(const int room) {
    rooms.insert(room);
}

const std::set<std::string> &InfoBank::get_subjects() const {
    return subjects;
}

const std::set<int> &InfoBank::get_groups() const {
    return groups;
}

const std::set<int> &InfoBank::get_rooms() const {
    return rooms;
}

bool InfoBank::contains_subject(const std::string &str) const {
    return subjects.find(std::string(str)) != subjects.end();
}

bool InfoBank::contains_group(const int group) const {
    return groups.find(group) != groups.end();
}

bool InfoBank::contains_room(const int room) const {
    return rooms.find(room) != rooms.end();
}