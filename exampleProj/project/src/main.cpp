#include "UserInterface.hpp"
#include <iostream>
#include <string>

void help() {
    std::cout << "Usage:" << std::endl;
    std::cout << "help Print usage" << std::endl;
    std::cout << "login Login" << std::endl;
    std::cout << "logout Logout" << std::endl;
    std::cout << "report Print report" << std::endl;
    std::cout << "info Account info:" << std::endl;
    std::cout << "exit Exit" << std::endl;
}

int main() {
    UserInterface ui;
    help();
    while (true) {
        std::cout << "> ";
        std::string str;
        std::getline(std::cin, str);
        if (str == "login") {
            ui.login();
        } else if (str == "logout") {
            ui.logout();
        } else if (str == "report") {
            ui.report();
        } else if (str == "info") {
            ui.info();
        } else if (str == "help") {
            help();
        } else if (str == "exit") {
            return 0;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}