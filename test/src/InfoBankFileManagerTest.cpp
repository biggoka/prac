#include "gtest/gtest.h"

#include <memory>

#include "InfoBank.hpp"
#include "InfoBankFileManager.hpp"




TEST(InfoBankFileManagerTest, basic) {
    auto bank = std::make_shared<InfoBank>();
    bank->add_room(1);
    bank->add_room(4);
    bank->add_room(8);

    bank->add_subject("matan");
    bank->add_subject("gelsdkjflsd");

    bank->add_group(101);
    bank->add_group(103);
    bank->add_group(107);

    InfoBankFileManager::write(bank);
    auto new_bank = InfoBankFileManager::read();

    ASSERT_EQ(true, bank->is_equal(*(new_bank)));


}
