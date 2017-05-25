#pragma once

#include "Predicate.hpp"

#include <memory>

class BinaryPredicate : public Predicate {
public:
    void accept(PredicateVisitor &);

public:

    std::shared_ptr<Predicate> leftOperand;
    std::shared_ptr<Predicate> rightOperand;

    std::shared_ptr<Predicate> copy();

};