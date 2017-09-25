    #include "complex.h"
#include <iostream>
#include <sstream>

bool Complex:: operator==(const Complex& rhs) const
{
    return (re == rhs.re) && (im == rhs.im);
}
bool Complex:: operator!=( const Complex& rhs) const 
{
    return !operator==(rhs);
}
 std::ostream& operator << (std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}
 std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}
Complex::Complex(const double real) 
    :Complex(real, 0.0)
{
}
Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{}
Complex& Complex::operator+=(const Complex& rhs) 
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(rhs.re + lhs.re, lhs.im + rhs.im);
}
Complex& Complex:: operator-=(const Complex& rhs) //но это не точно
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex& Complex:: operator*=(const Complex& rhs)
{
    re = re*rhs.re - im*rhs.im;
    im = re*rhs.im + im*rhs.re;
    return *this;
}
Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re*rhs.re - lhs.im*rhs.im, lhs.re*rhs.im + lhs.im*rhs.re);
}
Complex& Complex::operator +=(const double rhs) 
{
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const double rhs) 
{
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const double rhs)
{
    return operator*=(Complex(rhs));
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}
std::istream& Complex::readFrom(std::istream &istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaginary;

        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }

    }
    return istrm;
}