#include "ReportController.hpp"
#include "Transaction.hpp"
#include "User.hpp"
#include "FileReader.hpp"
#include "Report.hpp"

ReportController::ReportController(std::string filename) :
            reader(std::shared_ptr<FileReader>(new FileReader(filename))) {}

std::shared_ptr<Report> ReportController::make_report(
            const User & user,
            const Date & from_date,
            const Date & to_date) const {
    std::vector<std::shared_ptr<Transaction>> transactions = reader->transactions();
    std::vector<std::shared_ptr<Transaction>> res_transactions;
    int income = 0;
    int outcome = 0;
    for (std::shared_ptr<Transaction> & t : transactions) {
        if (from_date <= t->get_date() && t->get_date() <= to_date
               && (user.get_account() == t->get_from() || user.get_account() == t->get_to()) ) {
            res_transactions.push_back(t);
            if (user.get_account() == t->get_from()) {
                outcome += t->get_amount();
            }
            if (user.get_account() == t->get_to()) {
                income += t->get_amount();
            }
        }
    }
    return std::shared_ptr<Report> (
            new Report(
                res_transactions,
                Report::Summary(income, outcome, income - outcome)
            ));
}