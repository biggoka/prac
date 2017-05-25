#include "ImpPredicate.hpp"

#include "PredicateVisitor.hpp"

void ImpPredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}

std::shared_ptr<Predicate> ImpPredicate::copy() {
    auto pred = std::make_shared<ImpPredicate>();
    pred->leftOperand = leftOperand->copy();
    pred->rightOperand = rightOperand->copy();
    return pred;
}