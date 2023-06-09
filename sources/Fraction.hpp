#ifndef FRACTION_HPP
#define FRACTION_HPP

namespace ariel {
}

using namespace ariel;

#include <iostream>
#include <cmath>

class Fraction {
private:
    int numerator, denominator;

    void setNumerator(int num);
    void setDenominator(int num);

public:
    // Constructor
    Fraction();
    Fraction(int num, int den);
    Fraction(float num);

    // Getters
    int getNumerator() const;
    int getDenominator() const;

    // Overloaded operators
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);
    friend bool operator==(const Fraction& frac1, const Fraction& frac2);
    friend bool operator!=(const Fraction& frac1, const Fraction& frac2);
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);
    friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
    friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);

    // Friends
    friend std::ostream& operator<<(std::ostream& output_stream, const Fraction& frac);
    friend std::istream& operator>>(std::istream& input_stream, Fraction& frac);

private:
    // Private method to reduce the fraction
    void reduce();
};

#endif
