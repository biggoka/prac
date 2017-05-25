#include "NegatePredicate.hpp"

#include "PredicateVisitor.hpp"

void NegatePredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}


std::shared_ptr<Predicate> NegatePredicate::copy() {
    auto pred = std::make_shared<NegatePredicate>();
    pred->operand = operand->copy();
    return pred;
}