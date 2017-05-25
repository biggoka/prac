#include "Parser.hpp"

#include <memory>
#include <string>
#include <exception>

#include "InfoBank.hpp"

#include "Predicate.hpp"
#include "ImpPredicate.hpp"
#include "OrPredicate.hpp"
#include "AndPredicate.hpp"
#include "NegatePredicate.hpp"
#include "RelationPredicate.hpp"

void incorrect() {
    throw std::invalid_argument("Incorrect input");
}

Parser::Parser(std::shared_ptr<InfoBank> _bank)
    : bank(_bank)
{

}

void Parser::get_token() {
    do {
        token = stream.get();
    } while (isspace(token));
}

void Parser::expect(const char &ch) {
    if (token != ch) {
        incorrect();
    } else {
        get_token();
    }
}

void Parser::expect(const std::string &str) {
    std::string word;
    stream >> word;
    if (word != str) {
        incorrect();
    } else {
        get_token();
    }
}

int Parser::get_field() {
    switch (token) {
    case 'l' :
        expect("n");
        return Field::LECTURE_NUMBER;

    case 'w' :
        expect("d");
        return Field::WEEK_DAY;

    case 'r' :
        expect("oom");
        return Field::ROOM;    
    }
    incorrect();
    return 0;
}

int Parser::get_relation() {
    switch (token) {
    case '<' : 
        get_token();
        if (token == '=') {
            get_token();
            return Relation::LESS_EQUAL;
        } else {
            return Relation::LESS;
        }

    case '>' :
        get_token();
        if (token == '=') {
            get_token();
            return Relation::MORE_EQUAL;
        } else {
            return Relation::MORE;
        }
    case '=' :
        get_token();
        expect('=');
        return Relation::EQUAL;
    }
    incorrect();
    return 0;
}

int Parser::get_value() {
    if (token <= '9' and token >= '0') {
        stream.putback(token);
        int value;
        stream >> value;
        get_token();
        return value;
    }
    incorrect();
    return 0;
}

std::shared_ptr<Predicate> Parser::final() {
    auto res = std::make_shared<RelationPredicate>();

    res->field = get_field();
    res->relation = get_relation();
    res->value = get_value();

    return res;
}

std::shared_ptr<Predicate> Parser::parenthesis() {
    if (token == '(') {
        get_token();

        auto res = implication();

        expect(')');

        return res;
    }

    return final();
}

std::shared_ptr<Predicate> Parser::negation() {
    if (token == '!') {
        get_token();

        auto res = std::make_shared<NegatePredicate>();
        res->operand = parenthesis();

        return res;
    }

    return parenthesis();
}

std::shared_ptr<Predicate> Parser::conjunction() {
    auto left = negation();

    if (token == '&') {
        get_token();

        auto right = conjunction();

        auto res = std::make_shared<AndPredicate>();
        res->leftOperand = left;
        res->rightOperand = right;

        return res;
    }
    
    return left;
}

std::shared_ptr<Predicate> Parser::disjunction() {
    auto left = conjunction();

    if (token == '|') {
        get_token();

        auto right = disjunction();


        auto res = std::make_shared<OrPredicate>();
        res->leftOperand = left;
        res->rightOperand = right;

        return res;
    }

    return left;
}

std::shared_ptr<Predicate> Parser::implication() {
    auto left = disjunction();

    if (token == '-') {
        get_token();
        if (token == '>') {
            get_token();

            auto res = std::make_shared<ImpPredicate>();


            res->leftOperand = left;
            res->rightOperand = implication();

            return res;
        } else {
            incorrect();
        }
    }

    return left;
}

std::shared_ptr<Predicate> Parser::parse(const std::string &str) {
    stream.str(str);
    stream.clear();

    get_token();
    auto res = implication();
    if (!stream.eof()) {
        incorrect();
    }
    return res;
}