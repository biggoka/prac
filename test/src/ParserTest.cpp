#include "gtest/gtest.h"

#include "Parser.hpp"
#include "Predicate.hpp"
#include "RelationPredicate.hpp"
#include "OrPredicate.hpp"
#include "AndPredicate.hpp"
#include "ImpPredicate.hpp"
#include "InfoBank.hpp"

#include "Constants.hpp"

#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

TEST(ParserTest, FieldTest) {
    Parser parser(std::make_shared<InfoBank>());

    ASSERT_NO_THROW(parser.parse("ln > 4"));
    ASSERT_NO_THROW(parser.parse("room > 4"));
    ASSERT_NO_THROW(parser.parse("wd > 4"));

    ASSERT_NO_THROW(parser.parse("  wd > 4"));
    ASSERT_NO_THROW(parser.parse("   wd > 4"));
    ASSERT_NO_THROW(parser.parse("      wd > 4"));

    ASSERT_ANY_THROW(parser.parse("sdf > 3"));
}

TEST(ParserTest, RelatioinTest) {
    Parser parser(std::make_shared<InfoBank>());

    ASSERT_NO_THROW(parser.parse("ln > 3"));
    ASSERT_NO_THROW(parser.parse("ln >= 3"));
    ASSERT_NO_THROW(parser.parse("ln < 3"));
    ASSERT_NO_THROW(parser.parse("ln >= 3"));
    ASSERT_NO_THROW(parser.parse("ln == 3"));

    ASSERT_ANY_THROW(parser.parse("ln <><= 3"));
    ASSERT_ANY_THROW(parser.parse("ln <> 3"));
    ASSERT_ANY_THROW(parser.parse("ln >< 3"));
    ASSERT_ANY_THROW(parser.parse("ln ! 3"));
    ASSERT_ANY_THROW(parser.parse("ln + 3"));
    ASSERT_ANY_THROW(parser.parse("ln - 3"));
}   

TEST(ParserTest, ValueTest) {
    Parser parser(std::make_shared<InfoBank>());

    ASSERT_NO_THROW(parser.parse("ln > 0   "));
    ASSERT_NO_THROW(parser.parse("ln > 90  "));
    ASSERT_NO_THROW(parser.parse("ln > 50000  "));
}

TEST(ParserTest, SimpleTest) {
    Parser parser(std::make_shared<InfoBank>());

    ASSERT_NO_THROW(parser.parse("ln > 1 | ln > 2"));
    ASSERT_NO_THROW(parser.parse("ln > 1 & ln > 2"));
    ASSERT_NO_THROW(parser.parse("ln > 1 -> ln > 2"));
    ASSERT_NO_THROW(parser.parse("(ln > 1)"));
    ASSERT_NO_THROW(parser.parse("!(ln > 1)"));
}

TEST(ParserTest, MediumTest) {
    Parser parser(std::make_shared<InfoBank>());

    ASSERT_NO_THROW(parser.parse("(ln > 1) | (ln < 1) | (ln > 3)"));
    ASSERT_NO_THROW(parser.parse("(ln > 1) & (ln < 1) & (ln > 3)"));
    ASSERT_NO_THROW(parser.parse("ln > 1 & ln < 1 & ln > 3"));
    ASSERT_NO_THROW(parser.parse("(ln > 1) -> (!(ln > 1) & ln < 3)"));
    ASSERT_NO_THROW(parser.parse("(!(ln > 1) & (ln > 3)) -> (!(ln > 1) & ln < 3)"));  
}

TEST(ParserTest, PredicateTest1) {
    Parser parser(std::make_shared<InfoBank>());

    try {
        auto pred = parser.parse("ln < 1");
        std::shared_ptr<RelationPredicate> rel = std::dynamic_pointer_cast<RelationPredicate>(pred);
        ASSERT_EQ(Field::LECTURE_NUMBER, rel->field);
        ASSERT_EQ(Relation::LESS, rel->relation);
        ASSERT_EQ(1, rel->value);
    } catch (...) {
        FAIL();
    }

    try {
        auto pred = parser.parse("room > 2");
        std::shared_ptr<RelationPredicate> rel = std::dynamic_pointer_cast<RelationPredicate>(pred);
        ASSERT_EQ(Field::ROOM, rel->field);
        ASSERT_EQ(Relation::MORE, rel->relation);
        ASSERT_EQ(2, rel->value);
    } catch (...) {
        FAIL();
    }

    try {
        auto pred = parser.parse("wd == 3");
        std::shared_ptr<RelationPredicate> rel = std::dynamic_pointer_cast<RelationPredicate>(pred);
        ASSERT_EQ(Field::WEEK_DAY, rel->field);
        ASSERT_EQ(Relation::EQUAL, rel->relation);
        ASSERT_EQ(3, rel->value);
    } catch (...) {
        FAIL();
    }

}

TEST(ParserTest, PredicateTest2) {
    Parser parser(std::make_shared<InfoBank>());

    try {
        auto pred = parser.parse("(ln > 1) | (ln > 1)");
        auto rel = std::dynamic_pointer_cast<OrPredicate>(pred);
        if (rel == 0) {
            FAIL();
        }

        auto left = std::dynamic_pointer_cast<RelationPredicate>(rel->leftOperand);
        if (left == 0) {
            FAIL();
        }

        auto right = std::dynamic_pointer_cast<RelationPredicate>(rel->rightOperand);
        if (right == 0) {
            FAIL();
        }


    } catch (...) {
        FAIL();
    }

    try {
        auto pred = parser.parse("(ln > 1) & (ln > 1)");
        auto rel = std::dynamic_pointer_cast<AndPredicate>(pred);
        if (rel == 0) {
            FAIL();
        }

        auto left = std::dynamic_pointer_cast<RelationPredicate>(rel->leftOperand);
        if (left == 0) {
            FAIL();
        }

        auto right = std::dynamic_pointer_cast<RelationPredicate>(rel->rightOperand);
        if (right == 0) {
            FAIL();
        }
    } catch (...) {
        FAIL();
    }

    try {
        auto pred = parser.parse("(ln > 1) -> (ln > 1)");
        auto rel = std::dynamic_pointer_cast<ImpPredicate>(pred);
        if (rel == 0) {
            FAIL();
        }

        auto left = std::dynamic_pointer_cast<RelationPredicate>(rel->leftOperand);
        if (left == 0) {
            FAIL();
        }

        auto right = std::dynamic_pointer_cast<RelationPredicate>(rel->rightOperand);
        if (right == 0) {
            FAIL();
        }
    } catch (...) {
        FAIL();
    }
}

TEST(ParserTest, sample) {
    Parser parser(std::make_shared<InfoBank>());
}




