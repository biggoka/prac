#pragma once

// #include "LoginController.hpp"
//#include "ReportController.hpp"
#include <memory>

#include "Interface.hpp"

//class User;

class UserInterface : public Interface {
public:
    void start();
    void exit();
};
