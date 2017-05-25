#include "UnaryPredicate.hpp"

#include "PredicateVisitor.hpp"
#include <memory>

void UnaryPredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}

std::shared_ptr<Predicate> UnaryPredicate::copy() {
    auto pred = std::make_shared<UnaryPredicate>();
    pred->operand = operand->copy();
    return pred;
}