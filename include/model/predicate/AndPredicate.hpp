#pragma once

#include "BinaryPredicate.hpp"

#include <memory>
#include "Predicate.hpp"

class PredicateVisitor;

class AndPredicate : public BinaryPredicate {
public:
    void accept(PredicateVisitor &);
    std::shared_ptr<Predicate> copy();
};