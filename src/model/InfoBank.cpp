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

void InfoBank::clear_subjects() {
    subjects = std::set<std::string>();
}

void InfoBank::clear_groups() {
    groups = std::set<int>();
}

void InfoBank::clear_rooms() {
    rooms = std::set<int>();
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

bool InfoBank::is_equal(const InfoBank &b) const {
    for (auto &sub: subjects) {
        if (!b.contains_subject(sub)) {
            return false;
        }
    }

    for (auto &sub: b.get_subjects()) {
        if (!contains_subject(sub)) {
            return false;
        }
    }

    for (auto &room: rooms) {
        if (!b.contains_room(room)) {
            return false;
        }
    }

    for (auto &room: b.get_rooms()) {
        if (!contains_room(room)) {
            return false;
        }
    }

    for (auto &group: groups) {
        if (!b.contains_group(group)) {
            return false;
        }
    }

    for (auto &group: b.get_groups()) {
        if (!contains_group(group)) {
            return false;
        }
    }



    return true;
}