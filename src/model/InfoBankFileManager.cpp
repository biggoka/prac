#include "InfoBankFileManager.hpp"

#include "InfoBank.hpp"
#include "Constants.hpp"

#include <memory>
#include <fstream>
#include <iostream>

void InfoBankFileManager::write(std::shared_ptr<InfoBank> bank) {

    std::ofstream stream;
    stream.open(Files::INFO_BANK_FILE);

    

    stream.close();
}