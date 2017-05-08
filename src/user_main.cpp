#include "Splitter.hpp"
#include "UserInterface.hpp"

#include <iostream>
#include <string>

void help() {
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "  help" << std::endl;
    std::cout << "  list_rooms - print all available rooms" << std::endl;
    std::cout << "  list_groups - print all groups" << std::endl;
    std::cout << "  list_requests - print all requests" << std::endl;
    std::cout << "  delete_requests - delete requests" << std::endl;
    std::cout << "  add_request - add request" << std::endl;
    std::cout << "  exit - Exit" << std::endl;
}


int main() {
    UserInterface ui;
    help();
    while (true) {
        std::cout << "> ";
        std::string str;
        std::getline(std::cin, str);
        if (str == "list_rooms") {
            ui.list_rooms();
        } else if (str == "list_groups") {
            ui.list_groups();
        } else if (str == "list_requests") {
            ui.list_requests();
        } else if (str == "delete_requests") {
            ;
        } else if (str == "help") {
            help();
        } else if (str == "exit") {
            return 0;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}