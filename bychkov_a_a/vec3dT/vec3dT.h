//
// Created by Александр on 15.10.2017.
//
#ifndef VEC3D_10
#define VEC3d_10

#include <iosfwd>
#include <cmath>
#include <iostream>
#include <iomanip>
template<typename T>
struct Vec3dT
{
public:
    Vec3dT() = default;
    Vec3dT(const double xv, const double yv, const double zv);
    Vec3dT(const Vec3dT& v);
    bool operator==(const Vec3dT<T>& lhs);
    bool operator!=(const Vec3dT<T>& lhs);
    Vec3dT<T>& operator+=(const Vec3dT<T> rhs);
    Vec3dT<T>& operator-=(const Vec3dT<T> rhs);
    Vec3dT<T>& operator*=(const double rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    T e = 1E-6;
    T x{ T() };
    T y{ T() };
    T z{ T() };
    static const char leftBrace{ '{' }; // нужно ли использовать T вместо T
    static const char rightBrace{ '}' };
    static const char separator{ ',' };
    static void angle_between_vector(Vec3dT& lhs, Vec3dT& rhs);
    static void leng(Vec3dT& rhs);
    static void vector(Vec3dT& lhs, Vec3dT& rhs);
    static void scal(Vec3dT& lhs, Vec3dT& rhs);
};
template<typename T>
Vec3dT<T>::Vec3dT(const double xv, const double yv, const double zv)
        :x(xv), y(yv), z(zv) {}

template<typename T>
Vec3dT<T>::Vec3dT(const Vec3dT<T>& v)
        : x(v.x), y(v.y), z(v.z) {}
template <typename T>
bool Vec3dT<T>:: operator==(const Vec3dT<T>& rhs) // +
{
    return ((std::abs(rhs.x - x) < e) && (std::abs(rhs.y - y) < e) && (std::abs(rhs.z - z) < e));
}
template <typename T>
bool Vec3dT<T>:: operator!=(const Vec3dT<T>& lhs) // +
{
    return !operator==(lhs);
}
template<typename T>
Vec3dT<T>& Vec3dT<T>::operator+=(const Vec3dT<T> rhs) // +
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}
template <typename T>
Vec3dT<T>& Vec3dT<T>::operator-=(const Vec3dT<T> rhs) // +
{
    x -=rhs.x;
    y-=rhs.y;
    z-=rhs.z;
    return *this;
}
template <typename T>
Vec3dT<T>& Vec3dT<T>::operator*=(const double rhs) // +
{
    x*=rhs;
    y*=rhs;
    z*=rhs;
    return *this;
}
template <typename T>
Vec3dT<T>& operator+(const Vec3dT<T> lhs, const Vec3dT<T> rhs)
{
    Vec3dT<T> summ(lhs);
    summ+=rhs;
    return  summ;
}
template <typename T>
Vec3dT<T>& operator-(const Vec3dT<T> lhs, const Vec3dT<T> rhs)
{
    Vec3dT<T> sub(lhs);
    sub-=rhs;
    return sub;
}
template <typename T>
void Vec3dT<T> :: angle_between_vector(Vec3dT& lhs, Vec3dT& rhs)
{
    using namespace std;
    double angle = acos((rhs.x*lhs.x + rhs.y*lhs.y + rhs.z*lhs.z) /
                        (sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z)*(sqrt(lhs.x*lhs.x + lhs.y*lhs.y + lhs.z*lhs.z))));
    angle = angle * 180/3.14;
    cout << setprecision(2)<< "Angle between " << "a and b" <<" is "<< angle << endl;
}
template <typename T>
void Vec3dT<T> :: leng(Vec3dT<T>& lhs)
{
    using namespace std;
    double leng_ = sqrt(pow(lhs.x, 2) + pow(lhs.y, 2) + pow(lhs.z, 2));
    cout << "Length of vector "<< lhs<<" " << setprecision(2) << leng_ << endl;
}
template <typename T>
void Vec3dT<T> :: vector(Vec3dT<T>& lhs, Vec3dT<T>& rhs)
{
    using namespace std;
    double i = lhs.y*rhs.z - lhs.z*rhs.y;
    double j = lhs.x*rhs.z - rhs.x*lhs.z;
    double k = lhs.x*rhs.y - rhs.x*lhs.y;
    double modul = sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));
    cout << "a x b = " << "(" << i << ")i + (" << -j << ")j + (" << k << ")k" << endl;
    cout << "|a x b| = " << modul << endl;
}
template <typename T>
void Vec3dT<T> ::scal(Vec3dT<T> &lhs, Vec3dT<T> &rhs)
{
    double scal = rhs.x*lhs.x + rhs.y* lhs.y + rhs.z*lhs.z;
    std:: cout << "a * b = " << scal << std::endl;
}
template <typename T>
std::ostream& operator << (std::ostream& ostrm, const Vec3dT<T>& rhs)
{
    return rhs.writeTo(ostrm);
}
template <typename T>
std::istream& operator >> (std::istream& istrm, Vec3dT<T>& rhs)
{
    return rhs.readFrom(istrm);
}
template <typename T>
std::ostream& Vec3dT<T>::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace<< x <<separator << y <<separator<<z<<rightBrace;
    return ostrm;
}
template<typename T>
std::istream& Vec3dT<T>::readFrom(std::istream& istrm)
{
    char leftBrace(0), comma(0), rightBrace(0);
    double xv(0), yv(0), zv(0);
    istrm >> leftBrace >> xv >> comma >> yv >> comma >> zv >> rightBrace;
    if (istrm.good)
    {
        if ((Vec3dT<T>:: separator == comma) && (Vec3dT<T>:: x = xv) && (Vec3dT<T>:: y = yv))
            x=xv, y=yv, z=zv;
    }
    else
    {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
}
#endif

