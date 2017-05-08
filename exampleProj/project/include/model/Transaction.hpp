#include <string>
#include "Date.hpp"

class Transaction {
public:
    Transaction(Date date, int from, int to, int amount, std::string comment);
    Date get_date() const;
    int get_from() const;
    int get_to() const;
    int get_amount() const;
    std::string get_comment();
private:
    Date date;
    int from;
    int to;
    int amount;
    std::string comment;
};
