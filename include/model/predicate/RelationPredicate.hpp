#pragma once

#include "BinaryPredicate.hpp"

#include <memory>
#include "Predicate.hpp"

class RelationPredicate : public BinaryPredicate {
public:
    void accept(PredicateVisitor &);
    std::shared_ptr<Predicate> copy(); 

public:
    int relation;
    int field;
    int value;
};