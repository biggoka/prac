#pragma once

// #include "LoginController.hpp"
//#include "ReportController.hpp"
#include <memory>

#include "Interface.hpp"

//class User;

class UserInterface : public Interface {
public:
    void clear_requests();
    void add_request();

    //static Date read_date_cycle(const std::string &);

private:
    // std::shared_ptr<User> user;
    // LoginController login_controller;
    // ReportController report_controller;
};
