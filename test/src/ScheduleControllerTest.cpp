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
    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, sample) {

    auto bank = std::make_shared<InfoBank>();
    bank->add_room(1);
    bank->add_room(2);

    std::list<std::shared_ptr<Request>> requests;


    auto req = RequestMaker::make_request("108 matan slivinsky room == 1 & ln == 1  ", bank);
    requests.push_back(req);
    req = RequestMaker::make_request("101 matan kaledin room == 1 & ln == 1 & wd == 1  ", bank);
    requests.push_back(req);
    req = RequestMaker::make_request("108 matan slivinsky room == 1 & ln == 1  ", bank);
    // requests.push_back(req);
  

    std::cout << requests.size() << std::endl;

    
    ScheduleController controller;
    for (auto &req: requests) {
        controller.add_request(req);
    }

    ASSERT_EQ(true, controller.generate_schedule());

    controller.schedule.print();
}

