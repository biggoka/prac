#include "gtest/gtest.h"
#include "Splitter.hpp"
#include <vector>
#include <string>


TEST(SplitterTest, simpleInput) {
    std::string input = "hello there";
    std::vector<std::string> res = Splitter::split(input, ' ');
    ASSERT_EQ(2, res.size());
    ASSERT_EQ("hello", res[0]);
}

TEST(SplitterTest, emptyInput) {
    std::string input = "";
    std::vector<std::string> res = Splitter::split(input, ' ');
    ASSERT_EQ(0, res.size());
    //ASSERT_EQ("hello", res[0]);
}
