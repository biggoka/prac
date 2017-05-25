#pragma once

#include "Predicate.hpp"

#include <memory>

class UnaryPredicate : public Predicate {
public:
    void accept(PredicateVisitor &);
public:
    std::shared_ptr<Predicate> operand;
    std::shared_ptr<Predicate> copy();
};