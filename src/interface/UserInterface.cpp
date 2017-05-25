#include "UserInterface.hpp"

#include "InfoBankFileManager.hpp"
#include "RequestFileManager.hpp"
#include "RequestMaker.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <climits>


void UserInterface::start(){
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
        std::cout << "4. list requests" << std::endl;
        std::cout << "5. add request" << std::endl;

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
            list_requests();
            break;
        case 5:
            add_request();
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

void UserInterface::exit() {
    InfoBankFileManager::write(bank);
    RequestFileManager::write(requests);
}
