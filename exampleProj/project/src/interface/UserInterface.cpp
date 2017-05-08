#include "UserInterface.hpp"
#include <iostream>
#include <string>
#include "Transaction.hpp"
#include "Report.hpp"
#include "DateParser.hpp"
#include "User.hpp"

void UserInterface::login() {
    std::cout << "Enter login: ";
    std::string login;
    std::getline(std::cin, login);
    std::shared_ptr<User> user = login_controller.get_user(login);
    if (user != nullptr) {
        this->user = user;
        std::cout << "User login success." << std::endl;
    } else {
        std::cout << "Login failed!" <<  std::endl;
    }
}

void UserInterface::logout() {
    user = nullptr;
    std::cout << "Logout: OK" << std::endl;
}

void UserInterface::info() const {
    if (user != nullptr) {
        std::cout << "Login: " << user->get_login() << std::endl;
        std::cout << "Name: " << user->get_name() << std::endl;
        std::cout << "Account number: " << user->get_account() << std::endl;
        std::cout << "Account balance: " << user->get_balance() << std::endl;
    } else {
        std::cout << "You are not logged in!" <<  std::endl;
    }
};

Date UserInterface::read_date_cycle(const std::string & str) {
    std::string line;
    while (true) {
        std::cout << str;
        std::getline(std::cin, line);
        try {
            return DateParser::parse(line);
        } catch (std::invalid_argument) {
            std::cout << "WRONG DATE FORMAT! Please, try again" << std::endl;
        }
    }
}

void UserInterface::report() const {
    if (user == nullptr) {
        std::cout << "Error! User is not logged!" << std::endl;
        return ;
    }

    Date from_date = read_date_cycle("Enter FIRST date (DD:MM:YYYY): ");
    Date to_date = read_date_cycle("Enter LAST date (DD:MM:YYYY): ");

    std::shared_ptr<Report> report = report_controller.make_report(*user, from_date, to_date);

    std::cout << "Transactions:\nDATE" << "\t\t" << "FROM" << "\t" << "TO" << "\t" << "AMOUNT" << "\t" << "COMMENT" << std::endl;
    for (const std::shared_ptr<Transaction> & t : report->get_transactions()) {
        Date date = t->get_date();
        std::cout << date.get_day() << "." << date.get_month() << "." << date.get_year() << "\t";
        std::cout << t->get_from() << "\t" << t->get_to() << "\t";
        if (t->get_to() == user->get_account()) {
            std::cout << '+';
        }
        if (t->get_from() == user->get_account()) {
            std::cout << '-';
        }
        std::cout << t->get_amount() << "\t" << t->get_comment() << std::endl;
    }
    std::cout << std::endl;

    Report::Summary sum = report->get_summary();
    std::cout << "Income: " << sum.get_income() << std::endl;
    std::cout << "Outcome: " << sum.get_outcome() << std::endl;
    std::cout << "DELTA: " << sum.get_delta() << std::endl;
}

