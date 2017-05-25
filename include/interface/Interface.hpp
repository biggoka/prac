#pragma once

#include <list>
#include <memory>

#include "InfoBank.hpp"
#include "Request.hpp"


class Interface {
protected:
    std::shared_ptr<InfoBank> bank;
    std::list<std::shared_ptr<Request>> requests;
public:
    void list_rooms() const;
    void list_groups() const;
    void list_subjects() const;

    void add_request();

    void list_requests() const;
};
