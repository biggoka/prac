#include "ScheduleCellEntry.hpp"

#include <string>

ScheduleCellEntry::ScheduleCellEntry(int _group_id, int _room_id, \
    const std::string &_professor, const std::string &_subject)
    : subject(_subject)
    , professor(_professor)
    , group_id(_group_id)
    , room_id(_room_id)
{

}