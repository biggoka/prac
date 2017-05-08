#include "LoginController.hpp"
#include "ReportController.hpp"
#include <memory>

class User;

class UserInterface {
public:
    void login();
    void report() const;
    void logout();
    void info() const;

    static Date read_date_cycle(const std::string &);

private:
    std::shared_ptr<User> user;
    LoginController login_controller;
    ReportController report_controller;
};
