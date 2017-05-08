#include "Report.hpp"

Report::Summary::Summary(int income, int outcome, int delta) :
                delta(delta),
                income(income),
                outcome(outcome) {}

int Report::Summary::get_delta() const {
    return delta;
}

int Report::Summary::get_income() const {
    return income;
}

int Report::Summary::get_outcome() const {
    return outcome;
}


Report::Report(std::vector<std::shared_ptr<Transaction>> transactions, Summary summary) :
                transactions(transactions),
                summary(summary) {}

Report::Summary Report::get_summary() const {
    return summary;
}

const std::vector<std::shared_ptr<Transaction>> & Report::get_transactions() const {
    return transactions;
}

