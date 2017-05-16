#pragma once

#include <string>

class ScheduleCellEntry {

public:

    int group_id;
    int room_id;

    std::string professor;
    std::string subject;

    ScheduleCellEntry(int group_id, int room_id, const std::string &professor, const std::string &subject);

};