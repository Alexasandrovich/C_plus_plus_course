#include "complex.h"
#include <iostream>
#include <sstream>
#include <cmath>

bool Complex:: operator==(const Complex& rhs) const
{
    return (std::abs(re - rhs.re) < e) && (std::abs(im - rhs.im) < e);
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
{}
Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}
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
Complex operator+(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re + rhs, lhs.im);
}
Complex operator+(const double lhs, const Complex& rhs)
{
    return Complex(rhs.re + lhs, rhs.im);
}
Complex& Complex:: operator-=(const Complex& rhs) 
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator-(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re - rhs, lhs.im);
}
Complex operator-(const double lhs, const Complex& rhs)
{
    return Complex(rhs.re - lhs, rhs.im);
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
Complex operator*(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re*rhs, lhs.im*rhs);
}
Complex operator*(const double lhs, const Complex& rhs)
{
    return Complex(rhs.re*lhs, rhs.im * lhs);
}
Complex& Complex::operator/=(const Complex& rhs)
{
    re = (rhs.re*re + rhs.im*im) / (rhs.re*rhs.re + rhs.im*rhs.im);
    im = (rhs.re*im - re*rhs.im) / (rhs.re + rhs.im);
    return *this;
}
Complex operator/(const Complex& lhs, const Complex& rhs)
{
    return Complex((rhs.re*lhs.re + rhs.im*lhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im), 
        (rhs.re*lhs.im - rhs.re*lhs.im) / (rhs.re + rhs.im));
}
Complex operator/(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re / rhs, lhs.im / rhs);
}
Complex operator/(const double lhs, const Complex& rhs)
{
    return Complex((rhs.re-rhs.im)*lhs, rhs.re*rhs.re + rhs.im * rhs.re);
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
Complex& Complex::operator/=(const double rhs)
{
    return operator/=(Complex(rhs));
}
void Complex::exponentiation(Complex& rhs, int exponent)
{
    std::cout << "-------------" << std::endl;
    std::cout << "Exponentiation " << rhs << " in " << exponent << " degree"<<std::endl;
    int modul=sqrt(rhs.re*rhs.re + rhs.im*rhs.im), phi = atan(rhs.im / rhs.re);
    if (sin(exponent*phi) == 0)
    {
        std::cout << rhs << "^" << exponent << "=" << pow(modul, exponent) * cos(exponent*phi)<< std::endl;
    }
    else {
        std::cout << rhs << "^" << exponent << "=" << pow(modul, exponent) << "*(" << cos(exponent*phi)
            << sin(exponent*phi) << " i)" << std::endl;
    }
    std::cout << "-------------" << std::endl;
}
void Complex::extraction(Complex& rhs, int radical)
{
    int modul = pow(sqrt(rhs.re*rhs.re + rhs.im*rhs.im), 1 / radical), phi = atan(rhs.im / rhs.re);
    std::cout << "Extract the root " << radical << " degree from " << rhs<< std::endl;
    std::cout << "all radicals:" << std::endl;
    for (int k = 0; k < radical; k++)
    {
        if (sin(radical*phi) == 0)
        {
            std::cout << "z" << k << " = " << modul * cos((phi + 2 * 3.14*k) / radical) << std::endl;
        }
          else {
              if (sin((phi + 2 * 3.14*k) / radical) > 0){
                  std::cout << "z" << k << " = " << modul << "*(" << cos((phi + 2 * 3.14*k) / radical)
                      << "+" << sin((phi + 2 * 3.14*k) / radical) << " i)" << std::endl;
                 }
              else {
                  std::cout << "z" << k << " = " << modul << "*(" << cos((phi + 2 * 3.14*k) / radical)<<
                      sin((phi + 2 * 3.14*k) / radical) << " i)" << std::endl;
              }
              }
    }
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