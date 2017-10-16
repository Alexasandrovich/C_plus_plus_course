//
// Created by Александр on 15.10.2017.
//
#ifndef VEC3D_10
#define VEC3d_10

#include <iosfwd>
#include <cmath>
#include <iostream>
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
    Vec3dT<T>& operator*=(const Vec3dT<T> rhs);
    Vec3dT<T>& operator*=(const double rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
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
};
template<typename T>
Vec3dT<T>::Vec3dT(const double xv, const double yv, const double zv)
        :x(xv), y(yv), z(zv) {}

template<typename T>
Vec3dT<T>::Vec3dT(const Vec3dT<T>& v)
        : x(v.x), y(v.y), z(v.z) {}
template <typename T>
bool Vec3dT<T>:: operator==(const Vec3dT<T>& lhs) {
    return ((std::abs(lhs.x - lhs) < e) && (std::abs(lhs.y - lhs) < e) && (std::abs(lhs.z - lhs) < e));
}
template <typename T>
bool Vec3dT<T>:: operator!=(const Vec3dT<T>& lhs) {
    return !operator==(lhs);
}
template<typename T>
Vec3dT<T>& Vec3dT<T>::operator+=(const Vec3dT<T> rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}
template <typename T>
Vec3dT<T>& Vec3dT<T>::operator-=(const Vec3dT<T> rhs)
{
    x -=rhs.x;
    y-=rhs.y;
    z-=rhs.z;
}
template <typename T>
Vec3dT<T>& Vec3dT<T>::operator*=(const Vec3dT<T> rhs)
{
    x*=rhs.x;
    y*=rhs.y;
    z*=rhs.z;
}
template <typename T>
Vec3dT<T>& Vec3dT<T>::operator*=(const double rhs)
{
    x*=rhs;
    y*=rhs;
    z*=rhs;
}
template <typename T>
Vec3dT<T>& operator+(const Vec3dT<T> lhs, const Vec3dT<T> rhs);
template <typename T>
Vec3dT<T>& operator+(const Vec3dT<T> lhs, const Vec3dT<T> rhs)
{
    Vec3dT<T> summ(lhs);
    summ+=rhs;
    return summ;
}
template <typename T>
Vec3dT<T>& operator-(const Vec3dT<T> lhs, const Vec3dT<T> rhs);
template <typename T>
Vec3dT<T>& operator-(const Vec3dT<T> lhs, const Vec3dT<T> rhs)
{
    Vec3dT<T> sub(lhs);
    sub-=rhs;
    return sub;
}
template <typename T>
Vec3dT<T>& operator*(const Vec3dT<T> lhs, const Vec3dT<T> rhs);
template <typename T>
Vec3dT<T>& operator*(const Vec3dT<T> lhs, const Vec3dT<T> rhs)
{
    Vec3dT<T> mult(lhs);
    mult*=rhs;
    return mult;
}
template <typename T>
Vec3dT<T>& operator*(const Vec3dT<T> lhs, const double rhs)
{
    Vec3dT<T> mult(lhs);
    mult*=rhs;
    return mult;
}
template <typename T>
Vec3dT<T>& operator*(const double lhs, const Vec3dT<T> rhs)
{
    Vec3dT<T> mult(rhs);
    mult*=lhs;
    return mult;
}
template <typename T>
void Vec3dT<T> :: angle_between_vector(Vec3dT& lhs, Vec3dT& rhs)
{
    using namespace std;
    double angle =acos((lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z)/
            (sqrt(pow(rhs.x,2)+pow(rhs.y,2)+pow(rhs.z,2))*(sqrt(pow(lhs.x,2)+pow(lhs.y,2)+pow(lhs.z,2)))));
    cout << "Angle between a and b is " << angle << endl;
}
template <typename T>
void Vec3dT<T> :: leng(Vec3dT<T>& rhs)
{
    using namespace std;
    double lengt = sqrt(pow(rhs.x,2)+pow(rhs.y,2)+pow(rhs.z,2));
    cout << "The length of vector is " << lengt << endl;
}
template <typename T>
void Vec3dT<T> :: vector(Vec3dT<T>& lhs, Vec3dT<T>& rhs)
{
    using namespace std;
    double i=lhs.y*rhs.z-lhs.z*rhs.y;
    double j=lhs.x*rhs.z-lhs.z*rhs.x;
    double k=lhs.x*rhs.y-rhs.x*lhs.y;
    double modul = sqrt(pow(i,2)+pow(j,2)+pow(k,2));
    cout << "vector product module of a and b is " << modul << endl;
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

