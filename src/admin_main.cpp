#include "InfoBank.hpp"
#include "Parser.hpp"
#include "Predicate.hpp"
#include "NegatePredicate.hpp"


#include <string>
#include <memory>



int main() {

    auto neg1 = std::make_shared<NegatePredicate>();
    auto neg2 = std::make_shared<NegatePredicate>();

    neg1->operand = neg2;
    // neg2->operand = neg1;

}