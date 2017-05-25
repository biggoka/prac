#include "CaseMakerVisitor.hpp"

#include "Predicate.hpp"
#include "AndPredicate.hpp"
#include "OrPredicate.hpp"
#include "ImpPredicate.hpp"
#include "NegatePredicate.hpp"
#include "RelationPredicate.hpp"
#include "UnaryPredicate.hpp"
#include "BinaryPredicate.hpp"

#include "RequestCase.hpp"
#include "Constants.hpp"

#include <list>
#include <memory>
#include <iostream>

void unexpected() {
    throw "unexpected";
}

CaseMakerVisitor::CaseMakerVisitor(std::shared_ptr<InfoBank> _bank)
    : bank(_bank){

    }

void CaseMakerVisitor::visit(AndPredicate *predicate) {
    type = Type::AND;
}

void CaseMakerVisitor::visit(OrPredicate *predicate) {
    type = Type::OR;
}

void CaseMakerVisitor::visit(ImpPredicate *predicate) {
    type = Type::IMP;
}

void CaseMakerVisitor::visit(RelationPredicate *predicate) {
    type = Type::RELATION;
}

void CaseMakerVisitor::visit(NegatePredicate *predicate) {
    type = Type::NEGATE;
}

void CaseMakerVisitor::visit(BinaryPredicate *predicate) {
    unexpected();
}

void CaseMakerVisitor::visit(UnaryPredicate *predicate) {
    unexpected();
}

// std::list<std::shared_ptr<Request>> CaseMakerVisitor::make_requests(std::list<std::shared_ptr<Predicate>> &predicates) {
//     std::list<std::shared_ptr<Request>> requests;

//     for (auto &pred: predicates) {
        
//     }
// }

std::list<std::shared_ptr<RequestCase>> CaseMakerVisitor::make_cases(std::shared_ptr<Predicate> root) {
    if (root == 0) {
        std::cerr << "empty root in 'make_cases'";
        unexpected();
    }
    if (bank == 0) {
        std::cerr << "no bank provided in 'make_cases'";
        unexpected();
    }

    std::list<std::shared_ptr<RequestCase>> cases_list;

    auto predicates = make_predicates(root);

    for (auto &pred: predicates) {
        auto case_ = std::make_shared<RequestCase>();
        evaluate_case(case_, pred);

        // if (case_->time_options_count != 0 and case_->room_options_count != 0) {
        // }
        cases_list.push_back(case_);
    }
   

    return cases_list;
}

void CaseMakerVisitor::evaluate_case(std::shared_ptr<RequestCase> case_, std::shared_ptr<Predicate> pred) {

    for (int i = 1; i <= Constants::DAYS_IN_WEEK; i++) {
        for (int j = 1; j <= Constants::LECTURES_IN_DAY; j++) {
            if (evaluate(pred, i, j)){
                case_->days[i-1][j-1] = true;
                case_->time_options_count += 1;
            }
        }
    }

    auto rooms = bank->get_rooms();
    for (auto &room: rooms) {
        if (evaluate(pred, room)) {
            case_->rooms.insert(room);
            case_->room_options_count += 1;
        }
    }
}

bool CaseMakerVisitor::evaluate(std::shared_ptr<Predicate> root, int room) {

    if (root == 0) {
        unexpected();
    }
    root->accept(*this);

    switch(type) {
    case Type::AND :
        {
            auto pred = std::dynamic_pointer_cast<AndPredicate>(root);
            if (pred == 0) {
                unexpected();
            }
            return evaluate(pred->leftOperand, room) and evaluate(pred->rightOperand, room);
        };
        break;
    case Type::NEGATE :
        {
            auto pred = std::dynamic_pointer_cast<NegatePredicate>(root);
            if (pred == 0) {
                unexpected();
            }
            return !evaluate(pred->operand, room);
        };
        break;
    case Type::RELATION :
        {
            auto pred = std::dynamic_pointer_cast<RelationPredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            if (pred->field != Field::ROOM) {
                return true;
            }

            int value = pred->value;

            switch (pred->relation) {
            case Relation::MORE :
                return room > value;
                break;
            case Relation::MORE_EQUAL:
                return room >= value;
                break;
            case Relation::LESS:
                return room < value;
                break;
            case Relation::LESS_EQUAL:
                return room <= value;
                break;
            case Relation::EQUAL:
                return room == value;
                break;
            }
            unexpected();       

        };
        break;
    }
    unexpected();
    return false;
}

bool CaseMakerVisitor::evaluate(std::shared_ptr<Predicate> root, int i, int j) {

    if (root == 0) {
        unexpected();
    }
    root->accept(*this);

    switch(type) {
    case Type::AND :
        {
            auto pred = std::dynamic_pointer_cast<AndPredicate>(root);
            if (pred == 0) {
                unexpected();
            }
            return evaluate(pred->leftOperand, i, j) and evaluate(pred->rightOperand, i, j);
        };
        break;
    case Type::NEGATE :
        {
            auto pred = std::dynamic_pointer_cast<NegatePredicate>(root);
            if (pred == 0) {
                unexpected();
            }
            return !evaluate(pred->operand, i, j);
        };
        break;
    case Type::RELATION :
        {
            auto pred = std::dynamic_pointer_cast<RelationPredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            if (pred->field == Field::ROOM) {
                return true;
            }

            int value = pred->value;
            int field = pred->field;
            switch (pred->relation) {
            case Relation::MORE :
                if (field == Field::WEEK_DAY) {
                    return i > value;
                }
                if (field == Field::LECTURE_NUMBER) {
                    return j > value;
                }
                break;
            case Relation::MORE_EQUAL:
                if (field == Field::WEEK_DAY) {
                    return i >= value;
                }
                if (field == Field::LECTURE_NUMBER) {
                    return j >= value;
                }
                break;
            case Relation::LESS:
                if (field == Field::WEEK_DAY) {
                    return i < value;
                }
                if (field == Field::LECTURE_NUMBER) {
                    return j < value;
                }
                break;
            case Relation::LESS_EQUAL:
                if (field == Field::WEEK_DAY) {
                    return i <= value;
                }
                if (field == Field::LECTURE_NUMBER) {
                    return j <= value;
                }
                break;
            case Relation::EQUAL:
                if (field == Field::WEEK_DAY) {
                    return i == value;
                }
                if (field == Field::LECTURE_NUMBER) {
                    return j == value;
                }
                break;
            }
            unexpected();       

        };
        break;
    }
    unexpected();
    return false;
}



std::list<std::shared_ptr<Predicate>> CaseMakerVisitor::make_predicates(std::shared_ptr<Predicate> &root) {

    if (root == 0) {
        unexpected();
    }

    root->accept(*this);

    switch(type) {
    case Type::AND :
        {
            auto pred = std::dynamic_pointer_cast<AndPredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            std::list<std::shared_ptr<Predicate>> predicates;


            auto left = make_predicates(pred->leftOperand);
            auto right = make_predicates(pred->rightOperand);

            for (auto &left_pr: left) {
                for (auto &right_pr: right) {
                    auto and_pr = std::make_shared<AndPredicate>();
                    and_pr->leftOperand = left_pr->copy();
                    and_pr->rightOperand = right_pr->copy();

                    predicates.push_back(and_pr);
                }
            }

            return predicates;
        };
        break;
    case Type::OR :
        {
            auto pred = std::dynamic_pointer_cast<OrPredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            std::list<std::shared_ptr<Predicate>> predicates;


            auto left = make_predicates(pred->leftOperand);
            auto right = make_predicates(pred->rightOperand);

            for (auto &left_pr: left) {
                predicates.push_back(left_pr->copy());
            }

            for (auto &right_pr: right) {
                predicates.push_back(right_pr->copy());
            }

            return predicates;
        };
        break;
    case Type::IMP :
        {
            auto pred = std::dynamic_pointer_cast<ImpPredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            std::list<std::shared_ptr<Predicate>> predicates;


            auto left = make_predicates(pred->leftOperand);
            auto right = make_predicates(pred->rightOperand);

            for (auto &left_pr: left) {
                auto neg = std::make_shared<NegatePredicate>();
                neg->operand = left_pr->copy();
                predicates.push_back(neg);
            }

            for (auto &right_pr: right) {
                predicates.push_back(right_pr->copy());
            }

            return predicates;
        };
        break;
    case Type::NEGATE :
        {
            auto pred = std::dynamic_pointer_cast<NegatePredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            std::list<std::shared_ptr<Predicate>> predicates;


            auto rec = make_predicates(pred->operand);
            for (auto &pr: rec) {
                auto neg = std::make_shared<NegatePredicate>();
                neg->operand = pr;
                predicates.push_back(neg);
            }
            return predicates;
        };
        break;

    case Type::RELATION :
        {
            auto pred = std::dynamic_pointer_cast<RelationPredicate>(root);
            if (pred == 0) {
                unexpected();
            }

            std::list<std::shared_ptr<Predicate>> predicates;

            predicates.push_back(pred->copy());

            return predicates;
        };
        break;
    }

    unexpected();
    return std::list<std::shared_ptr<Predicate>>();
}