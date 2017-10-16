//
// Created by Александр on 16.10.2017.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

class Rational
{
public:
    Rational();
    Rational(const int number);
    Rational(const int integer, const int natural);
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
    ~Rational() = default;
private:
    int num{ 0 };
    int den{ 1 };
    double e = 1E-6;
    static const char division{ '/' };
    static void standard(Rational& rhs);
};
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const int lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const int lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const int lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const int lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int rhs);

#endif //RATIONAL_RATIONAL_H
