#include<memory>

class Report;
class User;
class FileReader;
class Date;

class ReportController {
public:
    ReportController(std::string filename = "transactions.txt");
    std::shared_ptr<Report> make_report(const User & user, const Date & from_date, const Date & to_date) const;
private:
    std::shared_ptr<FileReader> reader;
};