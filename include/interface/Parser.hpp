#pragma once



#include <sstream>
#include <memory>
#include <string>


class InfoBank;
class Predicate;

class Parser {

    std::shared_ptr<InfoBank> bank;

    int token;
    std::stringstream stream;

    void get_token();

    void expect(const char &);
    void expect(const std::string &);

    int get_field();
    int get_relation();
    int get_value();

    std::shared_ptr<Predicate> final();
    std::shared_ptr<Predicate> parenthesis();
    std::shared_ptr<Predicate> negation();
    std::shared_ptr<Predicate> conjunction();
    std::shared_ptr<Predicate> disjunction();
    std::shared_ptr<Predicate> implication();


public:

    Parser(std::shared_ptr<InfoBank> bank);

    std::shared_ptr<Predicate> parse(const std::string &);


};