#pragma once

#include "Interface.hpp"

#include <string>

class AdminInterface : public Interface {
public:
    void add_room(const size_t);
    void add_subject(const std::string &);
    void add_group(const size_t);

    void clear_rooms();
    void clear_subjects();
    void clear_groups();
    void clear_requests();

    void generate();
};