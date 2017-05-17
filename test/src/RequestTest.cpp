#include "gtest/gtest.h"

#include "Request.hpp"
#include <set>
#include <string>
#include <stdexcept>


TEST(RequestTest, empty) {
    Request req;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            ASSERT_EQ(false, req.day_is_set(i, j));
        }
    }
}

TEST(RequestTest, inserting) {
    Request req;

    req.set_day(1,3,false);
    ASSERT_EQ(false, req.day_is_set(1, 3));

    req.set_day(1,3,true);
    ASSERT_EQ(true, req.day_is_set(1,3));

    req.set_day(2,3,true);
    ASSERT_EQ(true, req.day_is_set(2, 3));

    req.set_day(3,7,false);
    ASSERT_EQ(false, req.day_is_set(3, 7));

    req.set_day(7,1,true);
    ASSERT_EQ(true, req.day_is_set(7, 1));


}

TEST(RequestTest, exception) {
    Request req;

    try {
        req.set_day(1,0, true);
        FAIL();
    } catch (std::invalid_argument &ex) {

    } catch (...) {
        FAIL();
    }

    try {
        req.set_day(8,1, true);
        FAIL();
    } catch (std::invalid_argument &ex) {

    } catch (...) {
        FAIL();
    }
}
