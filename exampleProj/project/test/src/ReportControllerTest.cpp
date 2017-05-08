#include "gtest/gtest.h"
#include "ReportController.hpp"
#include "User.hpp"
#include "Date.hpp"
#include "Report.hpp"
#include <memory>

TEST(ReportControllerTest, NoTransactionsUser) {
    ReportController controller("test/test_transactions.txt");
    //User with id=100
    std::shared_ptr<Report> report = controller.make_report(User("Ivan", "ivan", 100, 0), Date(1,1,2015), Date(31,12,2016));
    Report::Summary summary = report->get_summary();
    ASSERT_EQ(0, summary.get_delta());
    ASSERT_EQ(0, summary.get_income());
    ASSERT_EQ(0, summary.get_outcome());
    ASSERT_EQ(0, report->get_transactions().size());
}

TEST(ReportControllerTest, NoTransactionsInterval) {
    ReportController controller("test/test_transactions.txt");
    std::shared_ptr<Report> report = controller.make_report(User("Ivan", "ivan", 1, 0), Date(1,1,2016), Date(31,12,2016));
    Report::Summary summary = report->get_summary();
    ASSERT_EQ(0, summary.get_delta());
    ASSERT_EQ(0, summary.get_income());
    ASSERT_EQ(0, summary.get_outcome());
    ASSERT_EQ(0, report->get_transactions().size());
}

TEST(ReportControllerTest, Normal1) {
    ReportController controller("test/test_transactions.txt");
    std::shared_ptr<Report> report = controller.make_report(User("Ivan", "ivan", 1, 0), Date(3,2,2015), Date(2,3,2015));
    Report::Summary summary = report->get_summary();
    ASSERT_EQ(2, report->get_transactions().size());
    ASSERT_EQ(100, summary.get_delta());
    ASSERT_EQ(300, summary.get_income());
    ASSERT_EQ(200, summary.get_outcome());
}

TEST(ReportControllerTest, Normal2) {
    ReportController controller("test/test_transactions.txt");
    std::shared_ptr<Report> report = controller.make_report(User("Ivan", "ivan", 1, 0), Date(2,2,2015), Date(2,2,2015));
    Report::Summary summary = report->get_summary();
    ASSERT_EQ(2, report->get_transactions().size());
    ASSERT_EQ(-200, summary.get_delta());
    ASSERT_EQ(0, summary.get_income());
    ASSERT_EQ(200, summary.get_outcome());
}
