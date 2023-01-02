//
// Created by Maksim Drachov on 02.01.2023.
//

#include "Division.h"

DivisionResult Division::divide() const {
    if (fraction.denominator == 0L) {
        throw DivisionByZero();
    }

    auto result = DivisionResult{fraction.numerator / fraction.denominator,
                                 fraction.numerator % fraction.denominator};

    return result;
}

