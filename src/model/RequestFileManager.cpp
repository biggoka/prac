#include "RequestFileManager.hpp"

#include "Constants.hpp"
#include "RequestMaker.hpp"
#include "InfoBank.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void RequestFileManager::write(std::list<std::shared_ptr<Request>> &requests) {

    std::ofstream stream;
    stream.open(Files::REQUESTS_FILE);

    for (auto &req: requests) {
        stream << req->representation << std::endl;
    }

    stream.close();
}

std::list<std::shared_ptr<Request>> RequestFileManager::read(std::shared_ptr<InfoBank> bank) {
    std::ifstream stream;
    stream.open(Files::REQUESTS_FILE);

    std::string str;
    std::list<std::shared_ptr<Request>> requests;

    while (!stream.eof()) {
        std::getline(stream, str);
        if (str == "") {
            break;
        }

        // std::cout << str << std::endl;

        auto req = RequestMaker::make_request(str, bank);
        requests.push_back(req);
    }

    stream.close();
    return requests;
}