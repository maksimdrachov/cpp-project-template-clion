//
// Created by Maksim Drachov on 02.01.2023.
//

#ifndef CPP_PROJECT_TEMPLATE_CLION_DIVISION_H
#define CPP_PROJECT_TEMPLATE_CLION_DIVISION_H

#include <iostream>
#include <stdexcept>

class DivisionByZero : public std::exception {
public:
    const char *what() {return "Division by zero is illegal"; }
};

struct Fraction {
    int numerator;
    int denominator;
};

struct DivisionResult {
    long division;
    long remainder;

    friend bool operator==(const DivisionResult &lhs, const DivisionResult &rhs) {
        return lhs.division == rhs.division ? lhs.remainder < rhs.remainder : lhs.division < rhs.division;
    }
};

class Division {
public:
    explicit Division(Fraction fraction) : fraction{fraction}, result{.division = 0, .remainder = 0} {}

    ~Division() = default;

    DivisionResult divide() const;

private:
    Fraction fraction;
    DivisionResult result;
};


#endif //CPP_PROJECT_TEMPLATE_CLION_DIVISION_H
