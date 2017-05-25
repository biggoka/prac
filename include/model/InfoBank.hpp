#pragma once

#include <set>
#include <string>

class InfoBank {
    std::set<std::string> subjects;
    std::set<int> groups;
    std::set<int> rooms;

public:
    void add_subject(const std::string &);
    void add_group(const int);
    void add_room(const int);

    const std::set<std::string> &get_subjects() const;
    const std::set<int> &get_groups() const;
    const std::set<int> &get_rooms() const;

    bool contains_subject(const std::string &) const;
    bool contains_group(const int) const;
    bool contains_room(const int) const;
};