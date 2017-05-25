#pragma once

class PredicateVisitor;

#include <memory>

class Predicate {
public:
    virtual void accept(PredicateVisitor &) = 0;
    virtual std::shared_ptr<Predicate> copy() = 0;
};