#pragma once

class Predicate;
class AndPredicate;
class OrPredicate;
class RelationPredicate;
class NegatePredicate;
class ImpPredicate;
class BinaryPredicate;
class UnaryPredicate;


class PredicateVisitor {
public:
    // virtual void visit(Predicate *);
    virtual void visit(AndPredicate *) = 0;
    virtual void visit(OrPredicate *) = 0;
    virtual void visit(RelationPredicate *) = 0;
    virtual void visit(NegatePredicate *) = 0;
    virtual void visit(ImpPredicate *) = 0;
    virtual void visit(BinaryPredicate *) = 0;
    virtual void visit(UnaryPredicate *) = 0;
};