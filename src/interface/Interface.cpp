#include "Interface.hpp"

#include "RequestMaker.hpp"
#include "Request.hpp"

#include <iostream>
#include <string>
#include <sstream>

void Interface::list_rooms() const {
    std::cout << "Rooms: " << std::endl;
    for (auto &room: bank->get_rooms()) {
        std::cout << room << std::endl;
    }
    std::cout << std::endl;
}

void Interface::list_groups() const {
    std::cout << "Groups: " << std::endl;
    for (auto &group: bank->get_groups()) {
        std::cout << group << std::endl;
    }
    std::cout << std::endl;
}

void Interface::list_subjects() const {
    std::cout << "Subjects: " << std::endl;
    for (auto &subject: bank->get_subjects()) {
        std::cout << subject << std::endl;
    }
    std::cout << std::endl;
}

void Interface::list_requests() const {
    std::cout << "Requests: " << std::endl;
    int i = 0;
    for (auto &req: requests) {
        std::cout << i++ << ": " << req->representation<< std::endl;
    }

    std::cout << std::endl;
}

void Interface::add_request() {
    std::cout << "Input your request in format \"group subject professor logic_expression\": \n";

    std::string str;
    std::stringstream ss;
    std::getline(std::cin, str);
    ss.str(str);

    try {
        requests.push_back(RequestMaker::make_request(str, bank));
    } catch (std::invalid_argument &ex) {
        std::cout << "Incorrect expression, try again" << std::endl;
    } catch (...) {
        std::cout << "Something went wrong, try again" << std::endl;
    }
    
}


