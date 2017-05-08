#pragma once

#include <set>
#include <string>

class InfoBank {
    std::set<std::string> subjects;
    std::set<size_t> groups;
    std::set<size_t> rooms;

public:
    void add_subject(const std::string &);
    void add_group(const size_t);
    void add_room(const size_t);

    const std::set<std::string> &get_subjects() const;
    const std::set<size_t> &get_groups() const;
    const std::set<size_t> &get_rooms() const;

    bool contains_subject(const std::string &) const;
    bool contains_group(const size_t) const;
    bool contains_room(const size_t) const;
};