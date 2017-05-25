#include "AndPredicate.hpp"

#include "PredicateVisitor.hpp"

void AndPredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}

std::shared_ptr<Predicate> AndPredicate::copy() {
    auto pred = std::make_shared<AndPredicate>();
    pred->leftOperand = leftOperand->copy();
    pred->rightOperand = rightOperand->copy();
    return pred;
}