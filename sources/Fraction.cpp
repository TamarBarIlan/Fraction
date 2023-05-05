#include <bits/stdc++.h>
#include "Fraction.hpp"

Fraction::Fraction()
    : numerator(0), denominator(1)
{
}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    if (den < 0)
    {
        setNumerator(-1 * num);
        setDenominator(-1 * denominator);
    }
    reduce();
}

Fraction::Fraction(float num)
{
    numerator = static_cast<int>(std::round(num * 1000));
    denominator = 1000;
    reduce();
}


// Overloaded operators
Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
    long num = static_cast<long>(frac1.numerator * frac2.denominator) + static_cast<long>(frac2.numerator * frac1.denominator);
    long den = static_cast<long>(frac1.denominator * frac2.denominator);
    if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
    {
        throw std::overflow_error("Fraction overflow error");
    }
    return Fraction((int)num, (int)den);
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{
    long num = static_cast<long>(frac1.numerator * frac2.denominator) - static_cast<long>(frac2.numerator * frac1.denominator);
    long den = static_cast<long>(frac1.denominator * frac2.denominator);
    if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
    {
        throw std::overflow_error("Fraction overflow error");
    }
    return Fraction((int)num, (int)den);
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    long num = static_cast<long>(frac1.numerator) * static_cast<long>(frac2.numerator);
    long den = static_cast<long>(frac1.denominator) * static_cast<long>(frac2.denominator);
    if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
    {
        throw std::overflow_error("Fraction overflow error");
    }
    return Fraction((int)num, (int)den);
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    if (frac2.numerator == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    long num = static_cast<long>(frac1.numerator) * static_cast<long>(frac2.denominator);
    long den = static_cast<long>(frac1.denominator) * static_cast<long>(frac2.numerator);
    if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
    {
        throw std::overflow_error("Fraction overflow error");
    }
    return Fraction((int)num, (int)den);
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

bool operator!= (const Fraction &frac1, const Fraction &frac2)
{
    return !(frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator);
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
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &frac)
{
    int num, den;
    char slash;

    if (!(is >> num >> den) || den == 0)
    {
        throw std::runtime_error("illegal input");
    }
    else
    {
        Fraction temp(num, den);
        frac = temp;
    }

    return is;
}

// Private method to reduce the fraction
void Fraction::reduce()
{
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0)
    {
        setNumerator(-1 * numerator);
        setDenominator(-1 * denominator);
    }
}

int Fraction::getNumerator() const
{
    return numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

void Fraction::setNumerator(int num)
{
    this->numerator = num;
}
void Fraction ::setDenominator(int num)
{
    this->denominator = num;
}
