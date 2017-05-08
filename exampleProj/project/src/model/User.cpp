#include "User.hpp"

User::User(std::string name, std::string login, int account, int balance) :
        name(name), login(login), account(account), balance(balance) {}

std::string User::get_name() const {
    return name;
}

std::string User::get_login() const {
    return login;
}

int User::get_account() const {
    return account;
}

int User::get_balance() const {
    return balance;
}