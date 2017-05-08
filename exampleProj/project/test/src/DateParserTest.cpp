#include "gtest/gtest.h"
#include "DateParser.hpp"
#include <string>
#include "Date.hpp"


TEST(DateParserTest, EmptyInput) {
    try{
        DateParser::parse("");
        FAIL();
    } catch (std::invalid_argument) {
        //OK
    } catch (...){
        FAIL();
    }
}

TEST(DateParserTest, TooMuch) {
    try{
        DateParser::parse("10:20:30:40");
        FAIL();
    } catch (std::invalid_argument) {
        //OK
    } catch (...){
        FAIL();
    }
}

TEST(DateParserTest, NonDigitsTail) {
    try{
        DateParser::parse("01:01:2000abc");
        FAIL();
    } catch (std::invalid_argument) {
        //OK
    } catch (...){
        FAIL();
    }
}

TEST(DateParserTest, NonDigits) {
    try{
        DateParser::parse("a:b:c");
        FAIL();
    } catch (std::invalid_argument) {
        //OK
    } catch (...){
        FAIL();
    }
}

TEST(DateParserTest, Normal) {
    Date date = DateParser::parse("15:03:1991");
    ASSERT_EQ(15, date.get_day());
    ASSERT_EQ(3, date.get_month());
    ASSERT_EQ(1991, date.get_year());
}

TEST(DateParserTest, ShortNormal) {
    Date date = DateParser::parse("1:03:1991");
    ASSERT_EQ(1, date.get_day());
    ASSERT_EQ(3, date.get_month());
    ASSERT_EQ(1991, date.get_year());
}