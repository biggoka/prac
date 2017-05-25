#include "BinaryPredicate.hpp"

#include "PredicateVisitor.hpp"

void BinaryPredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}

std::shared_ptr<Predicate> BinaryPredicate::copy() {
    auto pred = std::make_shared<BinaryPredicate>();
    pred->leftOperand = leftOperand->copy();
    pred->rightOperand = rightOperand->copy();
    return pred;
}