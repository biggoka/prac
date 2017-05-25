#pragma once

class Request;
class InfoBank;

#include <memory>
#include <string>
#include <list>

class RequestMaker {
public:
    static std::shared_ptr<Request> make_request(const std::string &str, std::shared_ptr<InfoBank> &bank);// group subject professor logic_expression
};