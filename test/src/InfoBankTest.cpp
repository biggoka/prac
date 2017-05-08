#include "gtest/gtest.h"
#include "InfoBank.hpp"
#include <set>
#include <string>


TEST(InfoBankTest, empty) {
    InfoBank bank;
    ASSERT_EQ(0, bank.get_groups().size());
    ASSERT_EQ(0, bank.get_rooms().size());
    ASSERT_EQ(0, bank.get_subjects().size());
    // ASSERT_EQ("hello", res[0]);
}

TEST(InfoBankTest, addRoom) {
    InfoBank bank;
    bank.add_room(1);
    bank.add_room(2);
    bank.add_room(2);

    ASSERT_EQ(2, bank.get_rooms().size());
    ASSERT_EQ(true, bank.contains_room(1));
    ASSERT_EQ(true, bank.contains_room(2));
    ASSERT_EQ(false, bank.contains_room(3));
}

TEST(InfoBankTest, addGroup) {
    InfoBank bank;
    bank.add_group(1);
    bank.add_group(2);
    bank.add_group(2);

    ASSERT_EQ(2, bank.get_groups().size());
    ASSERT_EQ(true, bank.contains_group(1));
    ASSERT_EQ(true, bank.contains_group(2));
    ASSERT_EQ(false, bank.contains_group(3));
}

TEST(InfoBankTest, addSubject) {
    InfoBank bank;
    bank.add_subject("matan");
    bank.add_subject("matan");
    bank.add_subject("linal");

    ASSERT_EQ(2, bank.get_subjects().size());
    ASSERT_EQ(true, bank.contains_subject("matan"));
    ASSERT_EQ(false, bank.contains_subject("matadn"));
}

