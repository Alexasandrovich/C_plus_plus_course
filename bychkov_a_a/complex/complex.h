#ifndef COMPLEX_H_20170921
#define COMPLEX_H_20170921

#include <iosfwd> 

struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };

    double e = 1E-6;
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
    static void exponentiation(Complex& rhs, int exponent);
    static void extraction(Complex& rhs, int radical);
};
std::ostream& operator << (std::ostream& ostrm, const Complex& rhs);
std::istream& operator >> (std::istream& istrm, Complex& rhs);

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double lhs, const Complex& rhs);
#endif
