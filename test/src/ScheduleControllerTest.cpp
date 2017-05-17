#include "gtest/gtest.h"

#include "ScheduleController.hpp"
#include "Schedule.hpp"
#include "Request.hpp"

#include <set>
#include <string>
#include <memory>


TEST(ScheduleController, empty) {
    ScheduleController controller;
    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, oneRequest) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;

    controller.add_request(std::make_shared<Request>(req));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, TwoDifferentDays) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,2, true);
    req2.professor = "Kaledin";
    req2.subject = "Matan";
    req2.group_id = 202;
    req2.room_id = 605;
    controller.add_request(std::make_shared<Request>(req2));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, TwoDifferentDays2) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.set_day(2,2, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.set_day(2,2, true);
    req2.professor = "Kaledin";
    req2.subject = "Matan";
    req2.group_id = 202;
    req2.room_id = 605;
    controller.add_request(std::make_shared<Request>(req2));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, TwoDifferentDays3) {
    ScheduleController controller;

    Request req;
    req.set_day(2,2, true);
    req.set_day(3,3, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(2,2, true);
    // req2.set_day(3,3, true);
    req2.professor = "Kaledin";
    req2.subject = "Matan";
    req2.group_id = 202;
    req2.room_id = 605;
    controller.add_request(std::make_shared<Request>(req2));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, ThreeDifferentDays) {
    ScheduleController controller;

    Request req;
    req.set_day(2,2, true);
    req.set_day(3,3, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(3,3, true);
    req2.set_day(4,4, true);
    req2.professor = "Kaledin";
    req2.subject = "Matan";
    req2.group_id = 202;
    req2.room_id = 605;
    controller.add_request(std::make_shared<Request>(req2));

    Request req3;
    req3.set_day(4,4, true);
    req3.set_day(2,2, true);
    req3.professor = "Kaledin";
    req3.subject = "Matan";
    req3.group_id = 202;
    req3.room_id = 605;
    controller.add_request(std::make_shared<Request>(req3));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, FourDifferentDays) {
    ScheduleController controller;

    Request req;
    req.set_day(2,2, true);
    req.set_day(3,3, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(3,3, true);
    req2.set_day(4,4, true);
    req2.professor = "Kaledin";
    req2.subject = "Matan";
    req2.group_id = 202;
    req2.room_id = 605;
    controller.add_request(std::make_shared<Request>(req2));

    Request req3;
    req3.set_day(4,4, true);
    req3.set_day(4,2, true);
    req3.professor = "Kaledin";
    req3.subject = "Matan";
    req3.group_id = 202;
    req3.room_id = 605;
    controller.add_request(std::make_shared<Request>(req3));

    Request req4;
    // req4.set_day(4,4, true);
    req4.set_day(2,2, true);
    req4.professor = "Kaledin";
    req4.subject = "Matan";
    req4.group_id = 202;
    req4.room_id = 605;
    controller.add_request(std::make_shared<Request>(req4));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, RoomConflict) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.professor = "Slivinsky";
    req2.subject = "British";
    req2.group_id = 203;
    req2.room_id = 605;
    controller.add_request(std::make_shared<Request>(req2));

    ASSERT_EQ(false, controller.generate_schedule());
}

TEST(ScheduleController, GroupConflict) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.professor = "Slivinsky";
    req2.subject = "British";
    req2.group_id = 202;
    req2.room_id = 606;
    controller.add_request(std::make_shared<Request>(req2));

    ASSERT_EQ(false, controller.generate_schedule());
}

TEST(ScheduleController, ProfessorConflict) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.professor = "Kaledin";
    req.subject = "Matan";
    req.group_id = 202;
    req.room_id = 605;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.professor = "Kaledin";
    req2.subject = "British";
    req2.group_id = 203;
    req2.room_id = 606;
    controller.add_request(std::make_shared<Request>(req2));

    ASSERT_EQ(false, controller.generate_schedule());
}

TEST(ScheduleController, GeneralTest1) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.professor = "prep1";
    req.subject = "sub1";
    req.group_id = 201;
    req.room_id = 601;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.professor = "prep2";
    req2.subject = "sub2";
    req2.group_id = 202;
    req2.room_id = 602;
    controller.add_request(std::make_shared<Request>(req2));

    Request req3;
    req3.set_day(1,1, true);
    req3.professor = "prep3";
    req3.subject = "sub3";
    req3.group_id = 203;
    req3.room_id = 603;
    controller.add_request(std::make_shared<Request>(req3));

    Request req4;
    req4.set_day(1,1, true);
    req4.professor = "prep4";
    req4.subject = "sub4";
    req4.group_id = 204;
    req4.room_id = 604;
    controller.add_request(std::make_shared<Request>(req4));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, GeneralTest2) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.set_day(2,2, true);
    req.professor = "prep1";
    req.subject = "sub1";
    req.group_id = 201;
    req.room_id = 601;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.professor = "prep2";
    req2.subject = "sub2";
    req2.group_id = 201;
    req2.room_id = 602;
    controller.add_request(std::make_shared<Request>(req2));

    Request req3;
    req3.set_day(1,1, true);
    req3.professor = "prep3";
    req3.subject = "sub3";
    req3.group_id = 203;
    req3.room_id = 603;
    controller.add_request(std::make_shared<Request>(req3));

    Request req4;
    req4.set_day(1,1, true);
    req4.professor = "prep4";
    req4.subject = "sub4";
    req4.group_id = 204;
    req4.room_id = 604;
    controller.add_request(std::make_shared<Request>(req4));

    ASSERT_EQ(true, controller.generate_schedule());
}

TEST(ScheduleController, GeneralTest3) {
    ScheduleController controller;

    Request req;
    req.set_day(1,1, true);
    req.set_day(2,2, true);
    req.set_day(3,3, true);
    req.professor = "prep1";
    req.subject = "sub1";
    req.group_id = 201;
    req.room_id = 601;
    controller.add_request(std::make_shared<Request>(req));

    Request req2;
    req2.set_day(1,1, true);
    req2.professor = "prep2";
    req2.subject = "sub2";
    req2.group_id = 201;
    req2.room_id = 602;
    controller.add_request(std::make_shared<Request>(req2));

    Request req3;
    req3.set_day(2,2, true);
    req3.professor = "prep3";
    req3.subject = "sub3";
    req3.group_id = 201;
    req3.room_id = 603;
    controller.add_request(std::make_shared<Request>(req3));

    Request req4;
    req4.set_day(1,1, true);
    req4.professor = "prep4";
    req4.subject = "sub4";
    req4.group_id = 204;
    req4.room_id = 604;
    controller.add_request(std::make_shared<Request>(req4));

    ASSERT_EQ(true, controller.generate_schedule());
}