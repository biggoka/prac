#include "Transaction.hpp"

Transaction::Transaction(Date date, int from, int to, int amount, std::string comment) :
            date(date),
            from(from),
            to(to),
            amount(amount),
            comment(comment) {}

Date Transaction::get_date() const {
    return date;
}

int Transaction::get_from() const {
    return from;
}

int Transaction::get_to() const {
    return to;
}

int Transaction::get_amount() const {
    return amount;
}

std::string Transaction::get_comment(){
    return comment;
}

