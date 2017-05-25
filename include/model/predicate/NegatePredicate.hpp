#pragma once

#include "UnaryPredicate.hpp"
#include "Constants.hpp"

#include <memory>
#include "Predicate.hpp"

class NegatePredicate : public UnaryPredicate {
public:
    void accept(PredicateVisitor &);
    std::shared_ptr<Predicate> copy();

};