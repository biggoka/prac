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

bool ScheduleCellEntry::operator==(const ScheduleCellEntry &entr) const {
    if (subject == entr.subject and \
        professor == entr.professor and \
        group_id == entr.group_id and \
        room_id == entr.room_id) {
        return true;
    }
    return false;
}