#include "gtest/gtest.h"

#include "CaseMakerVisitor.hpp"
#include "Parser.hpp"
#include "InfoBank.hpp"
#include "RequestCase.hpp"

#include "Predicate.hpp"
#include "AndPredicate.hpp"

#include <memory>
#include <list>





TEST(CaseMakerVisitorTest, q1) {
    Parser parser(0);
    auto pred = parser.parse("ln > 1");

    CaseMakerVisitor visitor(0);
    auto list = visitor.make_predicates(pred);

    ASSERT_EQ(1, list.size());
}

TEST(CaseMakerVisitorTest, q2) {
    Parser parser(0);
    auto pred = parser.parse("ln > 1 | ln > 1");

    CaseMakerVisitor visitor(0);
    auto list = visitor.make_predicates(pred);

    ASSERT_EQ(2, list.size());
}

TEST(CaseMakerVisitorTest, q3) {
    Parser parser(0);
    auto pred = parser.parse("!(ln > 1 | ln > 1) & (ln > 2 | ln > 3)");

    CaseMakerVisitor visitor(0);
    auto list = visitor.make_predicates(pred);

    ASSERT_EQ(4, list.size());
}

TEST(CaseMakerVisitorTest, q4) {
    Parser parser(0);
    auto pred = parser.parse("wd == 1 & ln == 1");

    CaseMakerVisitor visitor(std::make_shared<InfoBank>());
    auto cases = visitor.make_cases(pred);

    ASSERT_EQ(1, cases.size());
    ASSERT_EQ(true, cases.front()->day_is_set(1,1));

}

TEST(CaseMakerVisitorTest, q5) {
    Parser parser(0);
    auto pred = parser.parse("wd == 1 | ln == 1");

    CaseMakerVisitor visitor(std::make_shared<InfoBank>());
    auto cases = visitor.make_cases(pred);

    ASSERT_EQ(2, cases.size());
    ASSERT_EQ(true, cases.front()->day_is_set(1,1));
    ASSERT_EQ(false, cases.front()->day_is_set(2,1));
}

TEST(CaseMakerVisitorTest, q6) {
    Parser parser(0);
    auto pred = parser.parse("wd == 1");

    auto bank = std::make_shared<InfoBank>();
    bank->add_room(1);

    CaseMakerVisitor visitor(bank);
    auto cases = visitor.make_cases(pred);

    ASSERT_EQ(1, cases.size());
    ASSERT_EQ(1, cases.front()->rooms.size());
    ASSERT_EQ(true, cases.front()->day_is_set(1,1));
    ASSERT_EQ(false, cases.front()->day_is_set(2,1));
}

TEST(CaseMakerVisitorTest, q7) {
    Parser parser(0);
    auto bank = std::make_shared<InfoBank>();

    bank->add_room(1);
    auto pred = parser.parse("wd == 1 -> room == 1");

    CaseMakerVisitor visitor(bank);
    auto cases = visitor.make_cases(pred);

    ASSERT_EQ(2, cases.size());
    ASSERT_EQ(0, cases.front()->rooms.size());
    ASSERT_EQ(false, cases.front()->day_is_set(1,1));
    ASSERT_EQ(true, cases.front()->day_is_set(2,1));
}



