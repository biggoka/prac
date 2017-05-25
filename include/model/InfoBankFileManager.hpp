#pragma once

#include "InfoBank.hpp"

#include <memory>

class InfoBankFileManager {
public:
    static void write(std::shared_ptr<InfoBank> bank);
    static std::shared_ptr<InfoBank> read();
};