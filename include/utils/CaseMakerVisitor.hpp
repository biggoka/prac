#pragma once

#include "PredicateVisitor.hpp"

#include "RequestCase.hpp"
#include "InfoBank.hpp"

#include <list>
#include <memory>


class Predicate;
class AndPredicate;
class OrPredicate;
class RelationPredicate;
class NegatePredicate;
class ImpPredicate;
class BinaryPredicate;
class UnaryPredicate;



class CaseMakerVisitor : public PredicateVisitor {
public:

    std::shared_ptr<InfoBank> bank;

    enum Type {
        AND, OR, IMP, RELATION, NEGATE,
    };
    int type;

    virtual void visit(AndPredicate *);
    virtual void visit(OrPredicate *);
    virtual void visit(RelationPredicate *);
    virtual void visit(NegatePredicate *);
    virtual void visit(ImpPredicate *);
    virtual void visit(BinaryPredicate *);
    virtual void visit(UnaryPredicate *);

    CaseMakerVisitor(std::shared_ptr<InfoBank> bank);

    void evaluate_case(std::shared_ptr<RequestCase> case_, std::shared_ptr<Predicate> pred);

    bool evaluate(std::shared_ptr<Predicate> pred, int room);
    bool evaluate(std::shared_ptr<Predicate> pred, int i, int j);

    std::list<std::shared_ptr<RequestCase>> make_cases(std::shared_ptr<Predicate> root);
    std::list<std::shared_ptr<Predicate>> make_predicates(std::shared_ptr<Predicate> &root);

};