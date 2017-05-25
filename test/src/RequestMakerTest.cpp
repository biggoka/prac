#include "gtest/gtest.h"

#include "InfoBank.hpp"
#include "RequestMaker.hpp"
#include "Request.hpp"
#include <memory>

TEST(RequestMakerTest, simple) {
    auto bank = std::make_shared<InfoBank>();

    auto req = RequestMaker::make_request("107 matan kaledin room == 1", bank);
    ASSERT_EQ(req->cases.size(), 1);
    ASSERT_EQ(req->group_id, 107);
    ASSERT_EQ(req->subject, "matan");
    ASSERT_EQ(req->professor, "kaledin");
    ASSERT_EQ(req->cases.front()->rooms.size(), 0);

    bank->add_room(1);

    req = RequestMaker::make_request("208 angl sliva room == 1 | ln == 1", bank);
    ASSERT_EQ(req->cases.size(), 2);
    ASSERT_EQ(req->group_id, 208);
    ASSERT_EQ(req->subject, "angl");
    ASSERT_EQ(req->professor, "sliva");
    ASSERT_EQ(req->cases.front()->rooms.size(), 1);

    ASSERT_THROW(RequestMaker::make_request("208 angl sliva room == 1 | lsdfsdfn == 1", bank), std::invalid_argument);
}