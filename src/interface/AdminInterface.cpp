#include "AdminInterface.hpp"

#include "InfoBankFileManager.hpp"
#include "RequestFileManager.hpp"
#include "RequestMaker.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <climits>


void AdminInterface::add_room() {
    std::cout << "Input new room: ";

    int room;

    std::string str;
    std::stringstream ss;
    std::getline(std::cin, str);
    ss.str(str);
    ss >> room;


    if (room == 0) {
        std::cout << "Something wrong, try again" << std::endl;
    }
    bank->add_room(room);
}

void AdminInterface::add_subject() {
    std::cout << "Input new subject: ";
    std::string sub;


    std::string str;
    std::stringstream ss;
    std::getline(std::cin, str);
    ss.str(str);
    ss >> sub;


    bank->add_subject(sub);
}
void AdminInterface::add_group() {

    std::cout << "Input new group: ";
    int group;
    
    std::string str;
    std::stringstream ss;
    std::getline(std::cin, str);
    ss.str(str);
    ss >> group;

    if (group == 0) {
        std::cout << "Something wrong, try again" << std::endl;
    }
    bank->add_group(group);
}

void AdminInterface::clear_rooms() { 
    bank->clear_rooms();
    std::cout << "Rooms cleared" << std::endl;

}
void AdminInterface::clear_subjects(){
    bank->clear_subjects();
    std::cout << "subjects cleared" << std::endl;
}

void AdminInterface::clear_groups(){
    bank->clear_groups();
    std::cout << "groups cleared" << std::endl;
}

void AdminInterface::clear_requests(){
    requests = std::list<std::shared_ptr<Request>>();
    std::cout << "requests cleared" << std::endl;
}


void AdminInterface::generate_schedule(){

    std::list<std::shared_ptr<Request>> new_requests;

    for (auto &req: requests) {
        auto new_req = RequestMaker::make_request(req->representation, bank);
        new_requests.push_back(new_req);
    }

    requests = new_requests;

    schedule_controller = ScheduleController();
    for (auto &req: requests) {
        schedule_controller.add_request(req);
    }

    if (schedule_controller.generate_schedule(bank)) {
        std::cout << "Schedule generated!" << std::endl;
        schedule_controller.print();
    } else {
        std::cout << "Schedule can not be generated!" << std::endl;
    }
}


void AdminInterface::start(){
    bank = InfoBankFileManager::read();
    requests = RequestFileManager::read(bank);

    do {
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "1. list rooms" << std::endl;
        std::cout << "2. list subjects" << std::endl;
        std::cout << "3. list groups" << std::endl;
        std::cout << "4. clear rooms" << std::endl;
        std::cout << "5. clear subjects" << std::endl;
        std::cout << "6. clear groups" << std::endl;
        std::cout << "7. add room" << std::endl;
        std::cout << "8. add subject" << std::endl;
        std::cout << "9. add group" << std::endl;
        std::cout << "10. list requests" << std::endl;
        std::cout << "11. clear requests" << std::endl;
        std::cout << "12. add request" << std::endl;
        std::cout << "13. generate schedule" << std::endl;
        std::cout << "99. exit" << std::endl;

        int c;

        std::string str1;
        std::stringstream ss;
        std::getline(std::cin, str1);
        ss.str(str1);
        ss >> c;

        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "You entered: " << c << std::endl;

        switch(c) {
        case 1:
            list_rooms();
            break;
        case 2:
            list_subjects();
            break;
        case 3:
            list_groups();
            break;
        case 4:
            clear_rooms();
            break;
        case 5:
            clear_subjects();
            break;
        case 6:
            clear_groups();
            break;
        case 7:
            add_room();
            break;
        case 8:
            add_subject();
            break;
        case 9:
            add_group();
            break;
        case 10:
            list_requests();
            break;
        case 11:
            clear_requests();
            break;
        case 12:
            add_request();
            break;
        case 13:
            generate_schedule();
            break;
        case 99:
            exit();
            return;
            break;
        default:
            std::cout << "something wrong, try again" << std::endl;
            std::string str;
            std::getline(std::cin , str);
            break;
        }

    } while (true);
}

void AdminInterface::exit(){
    InfoBankFileManager::write(bank);
    RequestFileManager::write(requests);
}
