#include "RelationPredicate.hpp"

#include "PredicateVisitor.hpp"

void RelationPredicate::accept(PredicateVisitor &visitor) {
    visitor.visit(this);
}


std::shared_ptr<Predicate> RelationPredicate::copy() {
    return std::make_shared<RelationPredicate>(*this);
}