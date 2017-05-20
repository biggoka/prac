#pragma once

class PredicateVisitor;

class Predicate {
public:
    void accept(const PredicateVisitor &);
};