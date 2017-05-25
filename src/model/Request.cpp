#include "Request.hpp"
#include "Constants.hpp"

#include <stdexcept>

Request::Request() {
    
}


bool Request::operator==(const Request &r) const {
    if (cases != r.cases) {
        return false;
    }

    if (professor != r.professor or \
        subject != r.subject or \
        group_id != r.group_id) 
    {
        return false;
    }

    if (this != &r) {
        return false;
    }

    return true;

}

bool Request::equal_to(const Request &r) const {
    // if (cases != r.cases) {
    //     return false;
    // }

    if (professor != r.professor or \
        subject != r.subject or \
        group_id != r.group_id) 
    {
        return false;
    }


    return true;
}
