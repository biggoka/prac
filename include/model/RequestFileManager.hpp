#pragma once

#include <list>
#include <memory>
#include <iostream>

#include "Request.hpp"
#include "InfoBank.hpp"


class RequestFileManager {
public:
    static void write(std::list<std::shared_ptr<Request>> &requests);
    static std::list<std::shared_ptr<Request>> read(std::shared_ptr<InfoBank> bank);
};