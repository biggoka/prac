#pragma once

#include "BinaryPredicate.hpp"

#include <memory>
#include "Predicate.hpp"

class OrPredicate : public BinaryPredicate {
public:
    void accept(PredicateVisitor &);
    std::shared_ptr<Predicate> copy();

};