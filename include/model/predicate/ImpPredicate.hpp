#pragma once

#include "BinaryPredicate.hpp"

#include <memory>
#include "Predicate.hpp"

class ImpPredicate : public BinaryPredicate {
public:
    void accept(PredicateVisitor &);
    std::shared_ptr<Predicate> copy();
};