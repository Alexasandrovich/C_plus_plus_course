//
// Created by Александр on 19.10.2017.
//

#include "kvanternion.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Kvanternion::Kvanternion(const double iv, const double jv, const double kv, const double qv )
        :i(iv), j(jv), k(kv), q(qv) {}

Kvanternion::Kvanternion(const Kvanternion& rhs)
        :i(rhs.i), j(rhs.j), k(rhs.k), q(rhs.q) {}
std::ostream& operator << (std::ostream& ostrm, const Kvanternion& rhs) // +
{
    return rhs.writeTo(ostrm);
}
std::istream& operator >> (std::istream& istrm, Kvanternion& rhs) // +
{
    return rhs.readFrom(istrm);
}
bool Kvanternion:: operator=(const Kvanternion& rhs)
{
    i=rhs.i;
    j=rhs.j;
    k=rhs.k;
    q=rhs.q;
}
bool Kvanternion:: operator==(const Kvanternion& rhs) const
{
    return (abs(rhs.i-i<e) && abs(rhs.j-j<e) && abs(rhs.k-k<e) && abs(rhs.q-q>e));
}
bool Kvanternion::operator!=(const Kvanternion& rhs)
{
    return !operator==(rhs);
}
Kvanternion& Kvanternion:: operator+=(const Kvanternion& rhs)
{
    i=i+rhs.i;
    j=j+rhs.j;
    k=k+rhs.k;
    q=q+rhs.q;
    return *this;
}
Kvanternion operator+(const Kvanternion& lhs, const Kvanternion& rhs) // +
{
    Kvanternion summ(lhs);
    summ += rhs;
    return summ;
}
Kvanternion& Kvanternion:: operator-=(const Kvanternion& rhs)
{
    i=i-rhs.i;
    j=j-rhs.j;
    k=k-rhs.k;
    q=q-rhs.q;
    return *this;
}
Kvanternion operator-(const Kvanternion& rhs, const Kvanternion& lhs)
{
    Kvanternion sub = rhs;
    sub-=lhs;
    return  sub;
}
Kvanternion& Kvanternion:: operator*=(const Kvanternion& rhs)
{
    i=i*rhs.i+j*rhs.k;
    j=i*rhs.j+j*rhs.q;
    k=k*rhs.i+q*rhs.k;
    q=k*rhs.j+q*rhs.q;
    return *this;
}
Kvanternion operator*(const Kvanternion& lhs, const Kvanternion& rhs)
{
    Kvanternion mult = rhs;
    mult*=lhs;
    return  mult;
}
void Kvanternion::determenant(Kvanternion& rhs)
{
    int det=rhs.i*rhs.q-rhs.j*rhs.k;
    std::cout <<"det" << rhs << "=" <<det<< std::endl;
}
void Kvanternion::inverse_kvanternion(Kvanternion& rhs)
{
    int det=rhs.i*rhs.q-rhs.j*rhs.k;
    Kvanternion lhs = rhs;
    if (det!=0)
    {
        rhs.i=rhs.q/det;
        rhs.j=-rhs.j/det;
        rhs.k=-rhs.k/det;
        rhs.q=rhs.i/det;
        std::cout<< "the inverse matrix for" << lhs << " is " << rhs << std::endl;
    }
    else std::cout << "the inverse matrix does not exist"<< std::endl;
}
std::ostream& Kvanternion::writeTo(std::ostream& ostrm) const
{
    ostrm << leftbrace << i << separator << j << separator << k << separator << q << rightbrace;
    return ostrm;
}
std::istream& Kvanternion::readFrom(std::istream& istrm)
{
    double iv(0.0), jv(0.0), kv(0.0), qv(0.0);
    char leftbrace(0), rightbrace(0), comma(0);
    istrm >> leftbrace >> iv >> comma >> jv >> comma >> kv >> comma >> qv >> rightbrace;
    if (istrm.good())
    {
        if ((Kvanternion:: separator == comma) && (Kvanternion:: i==iv) && (Kvanternion:: j==jv))
        {
            i=iv, j=jv, k=kv, q=qv;
        }
    }
    else
    {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
}

