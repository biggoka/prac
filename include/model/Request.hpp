#pragma once

#include <string>
#include <list>

#include "Constants.hpp"
#include "RequestCase.hpp"
#include "Predicate.hpp"

class Request {
public:
    std::string professor;
    std::string subject;
    int group_id;

    std::list<std::shared_ptr<RequestCase>> cases;
    std::shared_ptr<Predicate> predicate;
    std::string representation;

    Request();

    bool operator==(const Request &r) const;
    bool equal_to(const Request &r) const;
};