#include "OrPredicate.hpp"

#include "PredicateVisitor.hpp"

void OrPredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}

std::shared_ptr<Predicate> OrPredicate::copy() {
    auto pred = std::make_shared<OrPredicate>();
    pred->leftOperand = leftOperand->copy();
    pred->rightOperand = rightOperand->copy();
    return pred;

}