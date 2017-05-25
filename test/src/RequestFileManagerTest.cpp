#include "gtest/gtest.h"

#include "RequestFileManager.hpp"

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


TEST(RequestFileManagerTest, basic) {
    auto bank = std::make_shared<InfoBank>();
    bank->add_room(1);
    bank->add_room(2);

    std::list<std::shared_ptr<Request>> requests;


    auto req = RequestMaker::make_request("108 matan slivinsky room == 1 & ln == 1 | ln == 1 | ln == 1 ", bank);
    requests.push_back(req);
    req = RequestMaker::make_request("101 matan kaledin room == 1 & ln == 1 & wd == 1  ", bank);
    requests.push_back(req);
    req = RequestMaker::make_request("108 matan slivinsky room == 1 & ln == 1  ", bank);

    RequestFileManager::write(requests);
    auto new_requests = RequestFileManager::read(bank);

    ASSERT_EQ(requests.size(), new_requests.size());
    ASSERT_EQ(requests.front()->cases.size(), new_requests.front()->cases.size());
    ASSERT_EQ(requests.back()->cases.size(), new_requests.back()->cases.size());
}
