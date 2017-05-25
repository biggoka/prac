#include "RequestMaker.hpp"

#include "Request.hpp"
#include "InfoBank.hpp"
#include "Parser.hpp"
#include "CaseMakerVisitor.hpp"
#include "RequestCase.hpp"
#include "Predicate.hpp"

#include <string>
#include <sstream>
#include <memory>
#include <list>
#include <exception>

void bad_input() {
    throw std::invalid_argument("bad input");
}

std::shared_ptr<Request> RequestMaker::make_request(const std::string &str, std::shared_ptr<InfoBank> &bank) {

    std::stringstream stream(str);

    int group_id;
    std::string subject;
    std::string professor;
    std::string logic_expression;

    stream >> group_id;
    stream >> subject;
    stream >> professor;

    if (stream.eof() or group_id == 0) {
        bad_input();
    }

    std::getline(stream, logic_expression);

    Parser parser(0);
    CaseMakerVisitor visitor(bank);


    auto pred = parser.parse(logic_expression);
    auto cases = visitor.make_cases(pred);

    auto request = std::make_shared<Request>();
    request->subject = subject;
    request->group_id = group_id;
    request->professor = professor;
    request->representation = std::string(str);
    request->predicate = pred->copy();
    request->cases = cases;

    return request;
}