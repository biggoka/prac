#include "InfoBankFileManager.hpp"

#include "InfoBank.hpp"
#include "Constants.hpp"

#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>

void InfoBankFileManager::write(std::shared_ptr<InfoBank> bank) {

    std::ofstream stream;
    stream.open(Files::INFO_BANK_FILE);

    for (auto &sub: bank->get_subjects()) {
        stream << sub << std::endl;
    }
    stream << std::endl;

    for (auto &group: bank->get_groups()) {
        stream << group << std::endl;
    }
    stream << std::endl;

    for (auto &room: bank->get_rooms()) {
        stream << room << std::endl;
    }
    stream << std::endl;

    stream.close();
}

std::shared_ptr<InfoBank> InfoBankFileManager::read() {

    std::ifstream stream;
    stream.open(Files::INFO_BANK_FILE);

    std::string str;
    auto bank = std::make_shared<InfoBank>();

    do {
        std::getline(stream, str);
        if (str == "") {
            break;
        }
        bank->add_subject(str);
    } while (true);

    do {
        std::getline(stream, str);
        if (str == "") {
            break;
        }
        std::stringstream ss(str);
        int group;
        ss >> group;
        bank->add_group(group);
    } while (true);

    do {
        std::getline(stream, str);
        if (str == "") {
            break;
        }
        std::stringstream ss(str);
        int room;
        ss >> room;
        bank->add_room(room);
    } while (true);

    stream.close();
    return bank;
}