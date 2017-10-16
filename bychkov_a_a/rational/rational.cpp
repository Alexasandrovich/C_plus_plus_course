//
// Created by Александр on 16.10.2017.
//
#include <iostream>
#include <sstream>
#include "rational.h"

bool Rational::operator==(const Rational& rhs) const // +
{
    return (std::abs(num - rhs.num)<e) && (std::abs(den == rhs.den)<e);
}
bool Rational::operator!=(const Rational& rhs) const // +
{
    return !operator==(rhs);
}
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) // +
{
    return rhs.writeTo(ostrm);
}
std::istream& operator >> (std::istream& istrm, Rational& rhs) // +
{
    return rhs.readFrom(istrm);
}
Rational::Rational(const int number) // +
        : num(number), den(1) {}
Rational::Rational(const int integer, const int natural) // +
        : num(integer), den(natural)
{
    if (natural==0) // +-
    {
        __throw_exception_again;
    }
}
int Evklid_s_method(int num, int den) // +
{
    while (num != den)
    {
        if (num > den)
            num = num - den;
        else
            den = den - num;
    }
    return num;
}
int NOK(int num, int den) // +
{
    return num*den / Evklid_s_method(num, den);
}
void Rational::standard(Rational& rhs)
{
    if (rhs.den < 0)
    {
        rhs.num *= -1;
        rhs.den *= -1;
    }
    const int a = Evklid_s_method(rhs.num, rhs.den);
    rhs.num /= a;
    rhs.den /= a;
}
Rational& Rational::operator+=(const Rational& rhs) // ???
{
    int  a(rhs.num), b(rhs.den), c = NOK(rhs.num, rhs.den);
    if (den != c)
    {
        num *= den/ c;
        den = c;
    }
    if (b != c)
    {
        a *= c / b;
    }
    num+= a;
    Rational::standard(*this);
    return *this;
}
Rational& Rational::operator+=(const int rhs)
{
    return operator+=(Rational(rhs));
}
Rational operator+(const Rational& lhs, const Rational& rhs) //  +
{
    Rational sum(lhs);
    sum += rhs;
    return sum;
}
Rational operator+(const int lhs, const Rational& rhs)
{
    Rational sum(rhs);
    sum += lhs;
    return sum;
}
Rational operator+(const Rational& lhs, const int rhs)
{
    Rational sum(lhs);
    sum += rhs;
    return sum;
}
Rational& Rational::operator-=(const Rational& rhs)
{
    int  a(rhs.num), b(rhs.den), c = NOK(rhs.num, rhs.den);
    if (den != c)
    {
        num *= den / c;
        den = c;
    }
    if (b != c)
    {
        a *= c / b;
    }
    num -= a;
    Rational::standard(*this);
    return *this;
}
Rational& Rational::operator-=(const int rhs)
{
    return operator+=(Rational(rhs));
}
Rational operator-(const Rational& lhs, const Rational& rhs)
{
    Rational sub(lhs);
    sub -= rhs;
    return sub;
}
Rational operator-(const Rational& lhs, const int rhs)
{
    Rational sub(lhs);
    sub -= rhs;
    return sub;
}
Rational operator-(const int lhs, const Rational& rhs) {
    Rational sub(rhs);
    sub -= lhs;
    return sub;
}
Rational& Rational:: operator*=(const Rational& rhs)
{
    den *= rhs.den;
    num *= rhs.num;
    Rational::standard(*this);
    return *this;
}
Rational& Rational::operator*=(const int rhs)
{
    return operator*=(Rational(rhs));
}
Rational operator*(const Rational& lhs, const Rational&  rhs)
{
    Rational mult(rhs);
    mult *= lhs;
    return mult;
}
Rational operator*(const Rational& lhs, const int rhs)
{
    Rational mult(lhs);
    mult*= rhs;
    return mult;
}
Rational operator*(const int lhs, const Rational& rhs)
{
    Rational mult(rhs);
    mult *= lhs;
    return mult;
}
Rational& Rational::operator/=(const Rational& rhs)
{
    num *= rhs.den;
    den *= rhs.num;
    Rational::standard(*this);
    return *this;
}
Rational& Rational::operator/=(const int rhs)
{
    return operator/=(Rational(rhs));
}
Rational operator/(const Rational& lhs, const Rational&  rhs)
{
    Rational div(rhs);
    div /= lhs;
    return div;
}
Rational operator/(const Rational& lhs, const int rhs)
{
    Rational div(lhs);
    div /= rhs;
    return div;
}
Rational operator/(const int lhs, const Rational& rhs)
{
    Rational div(rhs);
    div /= lhs;
    return div;
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num << division <<den;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    int integer(0);
    char division(0);
    int natural(0);
    istrm >> integer >> division >> natural;
    if (istrm.good()) {
        if (Rational::division == division) {
            num = integer;
            den = natural;

        }
        else {
            istrm.setstate(std::ios_base::failbit);

        }

    }
    return istrm;
}