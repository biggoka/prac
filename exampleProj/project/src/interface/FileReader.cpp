#include "FileReader.hpp"
#include <fstream>
#include "Transaction.hpp"
//#include <regex>
#include "User.hpp"
#include "Splitter.hpp"
#include <iostream>
#include "DateParser.hpp"

FileReader::FileReader(std::string filename) : filename(filename)  {}

std::vector<std::shared_ptr<Transaction>> FileReader::transactions() const {
    std::vector<std::shared_ptr<Transaction>> res;

    std::ifstream infile(filename);
    std::string line;

    Splitter line_splitter('|');
    Splitter date_splitter(':');

    while (std::getline(infile, line)) {
        std::vector<std::string> splitted = line_splitter.split(line);

        try {
            if (splitted.size() < 5) {
                throw std::invalid_argument("");
            }
            Date date = DateParser::parse(splitted[0]);
            int from = std::stoi(splitted[1]);
            int to = std::stoi(splitted[2]);
            int amount = std::stoi(splitted[3]);
            std::string comment = splitted[4];

            res.push_back(std::shared_ptr<Transaction>(new Transaction(date, from, to, amount, comment)));
        } catch (std::invalid_argument) {
            std::cerr << "WARNING: Transaction reading error!" << std::endl;
            continue ;
        }
    }

    return res;
}

std::vector<std::shared_ptr<User>> FileReader::users() const {
    std::vector<std::shared_ptr<User>> res;

    std::ifstream infile(filename);

    int from, to, amount;
    std::string comment;

    Splitter splitter(',');
    std::string line;

    while (std::getline(infile, line)) {
        std::vector<std::string> splitted = splitter.split(line);
        try {
            if (splitted.size() < 4) {
                throw std::invalid_argument("");
            }
            std::string name = splitted[0];
            std::string login = splitted[1];
            int account = std::stoi(splitted[2]);
            int balance = std::stoi(splitted[3]);

            res.push_back(std::shared_ptr<User>(new User(name, login, account, balance)));
        } catch (std::invalid_argument) {
            std::cerr << "WARNING: User reading error!" << std::endl;
            continue ;
        }
    }

    return res;
}