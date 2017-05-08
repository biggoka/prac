#include "InfoBank.hpp"

void InfoBank::add_subject(const std::string &str) {
    std::string st(str);
    subjects.insert(st);
}

void InfoBank::add_group(const size_t group) {
    groups.insert(group);
}

void InfoBank::add_room(const size_t room) {
    rooms.insert(room);
}

const std::set<std::string> &InfoBank::get_subjects() const {
    return subjects;
}

const std::set<size_t> &InfoBank::get_groups() const {
    return groups;
}

const std::set<size_t> &InfoBank::get_rooms() const {
    return rooms;
}

bool InfoBank::contains_subject(const std::string &str) const {
    return subjects.find(std::string(str)) != subjects.end();
}

bool InfoBank::contains_group(const size_t group) const {
    return groups.find(group) != groups.end();
}

bool InfoBank::contains_room(const size_t room) const {
    return rooms.find(room) != rooms.end();
}