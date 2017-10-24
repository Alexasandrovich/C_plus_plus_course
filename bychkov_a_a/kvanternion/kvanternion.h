//
// Created by Александр on 19.10.2017.
// Variant 2

#ifndef KVANTERNION_KVANTERNION_H
#define KVANTERNION_KVANTERNION_H

#include <iosfwd>
#include <iostream>
struct Kvanternion
{
public:
    Kvanternion()=default;
    Kvanternion(const double iv, const double jv, const double kv, const double qv);
    Kvanternion(const Kvanternion& v);
    bool operator=(const Kvanternion& rhs);
    bool operator==(const Kvanternion& rhs) const;
    bool operator!=(const Kvanternion& rhs);
    Kvanternion& operator+=(const Kvanternion& rhs);
    Kvanternion& operator-=(const Kvanternion& rhs);
    Kvanternion& operator*=(const Kvanternion& rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    double e = 1E-6;
    double i{0.0};
    double j{0.0};
    double k{0.0};
    double q{0.0};
    static void determenant(Kvanternion& rhs);
    static void inverse_kvanternion(Kvanternion& rhs);
    static const  char separator{','};
    static  const char leftbrace{'{'};
    static  const char rightbrace{'}'};
};
std::ostream& operator << (std::ostream& ostrm, const Kvanternion& rhs);
std::istream& operator >> (std::istream& istrm, const Kvanternion& rhs);

Kvanternion operator+(const Kvanternion& rhs, const Kvanternion& lhs);
Kvanternion operator-(const Kvanternion& rhs, const Kvanternion& lhs);
Kvanternion operator*(const Kvanternion& rhs, const Kvanternion& lhs);

#endif //KVANTERNION_KVANTERNION_H
