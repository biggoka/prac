#include "gtest/gtest.h"

#include "ScheduleController.hpp"
#include "Schedule.hpp"
#include "Request.hpp"
#include "Parser.hpp"
#include "Predicate.hpp"
#include "InfoBank.hpp"
#include "CaseMakerVisitor.hpp"
#include "RequestMaker.hpp"

#include <set>
#include <string>
#include <list>
#include <memory>
#include <iostream>


TEST(ScheduleController, empty) {
    ScheduleController controller;
    auto bank = std::make_shared<InfoBank>();
    ASSERT_EQ(true, controller.generate_schedule(bank));
}

TEST(ScheduleController, simple1) {

    auto bank = std::make_shared<InfoBank>();
    bank->add_room(1);
    bank->add_room(2);

    bank->add_subject("matan");

    bank->add_group(107);

    std::list<std::shared_ptr<Request>> requests;

    std::shared_ptr<Request> req;

    req = RequestMaker::make_request("107 matan kaledin room > 0", bank);
    requests.push_back(req);
    
    ScheduleController controller;
    for (auto &req: requests) {
        controller.add_request(req);
    }

    ASSERT_EQ(true, controller.generate_schedule(bank));
}

TEST(ScheduleController, simple2) {

    auto bank = std::make_shared<InfoBank>();
    bank->add_room(1);
    bank->add_room(2);

    bank->add_subject("matan");

    bank->add_group(107);

    std::list<std::shared_ptr<Request>> requests;

    std::shared_ptr<Request> req;

    req = RequestMaker::make_request("107 matan kaledin room > 0", bank);
    requests.push_back(req);
    
    ScheduleController controller;
    for (auto &req: requests) {
        controller.add_request(req);
    }

    ASSERT_EQ(true, controller.generate_schedule(bank));
}

