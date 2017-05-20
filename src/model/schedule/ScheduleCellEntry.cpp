#include "ScheduleCellEntry.hpp"

#include <string>

ScheduleCellEntry::ScheduleCellEntry(int _group_id, int _room_id, \
    const std::string &_professor, const std::string &_subject)
    : group_id(_group_id)
    , room_id(_room_id)
    , professor(_professor)
    , subject(_subject)
{

}

bool ScheduleCellEntry::operator==(const ScheduleCellEntry &entr) const {
    if( group_id == entr.group_id and \
        room_id == entr.room_id and \
        professor == entr.professor and \
        subject == entr.subject)
    {
        return true;
    }
    return false;
}