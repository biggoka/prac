#pragma once

// #include "LoginController.hpp"
//#include "ReportController.hpp"
// #include <memory>

//class User;

#include "InfoBank.hpp"

class Interface {
public:
    void list_rooms() const;
    void list_groups() const;
    void list_requests() const;

    //static Date read_date_cycle(const std::string &);

protected:
    InfoBank info_bank;
    // std::shared_ptr<User> user;
    // LoginController login_controller;
    // ReportController report_controller;
};
