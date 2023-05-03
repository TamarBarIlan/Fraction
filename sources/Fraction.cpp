#include <iostream>
#include <cmath>
#include <iomanip>
#include <numeric>
#include "Fraction.hpp"

Fraction:: Fraction()
{
    Fraction(0,1);
}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
{
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    reduce();
}


Fraction::Fraction(float num)
{
    int int_part = static_cast<int>(num);
    float frac_part = num - int_part;

    numerator = int_part * 1000 + static_cast<int>(frac_part * 1000);
    denominator = 1000;

    reduce();
}

// Overloaded operators
Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    int den = frac1.denominator * frac2.denominator;
    return Fraction(num, den);
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
    int den = frac1.denominator * frac2.denominator;
    return Fraction(num, den);
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.numerator * frac2.numerator;
    int den = frac1.denominator * frac2.denominator;
    return Fraction(num, den);
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    if (frac2.numerator == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    int num = frac1.numerator * frac2.denominator;
    int den = frac1.denominator * frac2.numerator;
    return Fraction(num, den);
}


bool operator==(const Fraction &frac1, const Fraction &frac2)
{
    return frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator;
}

bool operator<(const Fraction &frac1, const Fraction &frac2)
{
    int num1 = frac1.numerator * frac2.denominator;
    int num2 = frac2.numerator * frac1.denominator;
    return num1 < num2;
}

bool operator>(const Fraction &frac1, const Fraction &frac2)
{
    int num1 = frac1.numerator * frac2.denominator;
    int num2 = frac2.numerator * frac1.denominator;
    return num1 > num2;
}

bool operator<=(const Fraction &frac1, const Fraction &frac2)
{
    return frac1 < frac2 || frac1 == frac2;
}

bool operator>=(const Fraction &frac1, const Fraction &frac2)
{
    return frac1 > frac2 || frac1 == frac2;
}

Fraction Fraction::operator++()
{
    numerator += denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(numerator, denominator);
    numerator += denominator;
    reduce();
    return temp;
}

Fraction Fraction::operator--()
{
    numerator -= denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(numerator, denominator);
    numerator -= denominator;
    reduce();
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Fraction &frac)
{
    int num = frac.getNumerator();
    int deno = frac.getDenominator();
    Fraction temp(num,deno);
    os << temp.numerator << "/" << frac.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &frac)
{
    int num, den;
    char slash;

    if(!(is >> num >> den) || den == 0){
        throw std:: runtime_error("illegal input");
    }
    else{
        Fraction temp(num,den);
        frac = temp;
    }

    return is;
}




// Private method to reduce the fraction
void Fraction::reduce()
{
    // Find the greatest common divisor of the numerator and denominator
    int gcd = std::gcd(numerator, denominator);

    // Divide both numerator and denominator by gcd to reduce the fraction
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::getNumerator() const
{
    return numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}


