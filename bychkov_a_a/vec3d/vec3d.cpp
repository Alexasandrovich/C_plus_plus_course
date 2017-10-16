//
// Created by Александр on 16.10.2017.
//
#include "vec3d.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

Vec3d::Vec3d(const double xv, const double yv, const double zv) // +
        :x(xv), y(yv), z(zv) {}

Vec3d::Vec3d(const Vec3d& v) // +
        :x(v.x), y(v.y), z(v.z) {}
bool Vec3d:: operator==(const Vec3d& rhs) const // +
{
    return ((std::abs(rhs.x - x) < e) && (std::abs(rhs.y - y) < e) && (std::abs(rhs.z - z) < e));
}
bool Vec3d::operator!=(const Vec3d& rhs)const // +
{
    return !operator==(rhs);
}
bool Vec3d::operator=(const Vec3d& rhs)
{
    x=rhs.x;
    y=rhs.y;
    z=rhs.z;
}
/*bool Vec3d::operator>(const Vec3d& rhs)
{
    return ((x>rhs.x)&&(y>rhs.y)&&(z>rhs.z));
}
bool Vec3d::operator<(const Vec3d& rhs)
{
    return ((x<rhs.x)&&(y<rhs.y)&&(z<rhs.z));
}*/
std::ostream& operator << (std::ostream& ostrm, const Vec3d& rhs) // +
{
    return rhs.writeTo(ostrm);
}
std::istream& operator >> (std::istream& istrm, Vec3d& rhs) // +
{
    return rhs.readFrom(istrm);
}
Vec3d& Vec3d:: operator+=(const Vec3d& rhs) // +
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}
Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs) // +
{
    Vec3d summ(lhs);
    summ += rhs;
    return summ;
}
Vec3d& Vec3d:: operator-=(const Vec3d& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}
Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs)
{
    Vec3d sub(lhs);
    sub -= rhs;
    return sub;
}
Vec3d& Vec3d :: operator*=(const double rhs)
{
    x*=rhs;
    y*=rhs;
    z*=rhs;
    return *this;
}
void Vec3d :: angle_between_vector(Vec3d& lhs, Vec3d& rhs)
{
    using namespace std;
    double angle = acos((rhs.x*lhs.x + rhs.y*lhs.y + rhs.z*lhs.z) /
                        (sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z)*(sqrt(lhs.x*lhs.x + lhs.y*lhs.y + lhs.z*lhs.z))));
    angle = angle * 180/3.14;
    cout << setprecision(2)<< "Angle between " << "a and b" <<" is "<< angle << endl;
}
void Vec3d :: leng(Vec3d& lhs)
{
    using namespace std;
    double leng_ = sqrt(pow(lhs.x, 2) + pow(lhs.y, 2) + pow(lhs.z, 2));
    cout << "Length of vector "<< lhs<<" " << setprecision(2) << leng_ << endl;
}
void Vec3d :: vector(Vec3d& lhs, Vec3d& rhs)
{
    using namespace std;
    double i = lhs.y*rhs.z - lhs.z*rhs.y;
    double j = lhs.x*rhs.z - rhs.x*lhs.z;
    double k = lhs.x*rhs.y - rhs.x*lhs.y;
    double modul = sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));
    cout << "a x b = " << "(" << i << ")i + (" << -j << ")j + (" << k << ")k" << endl;
    cout << "|a x b| = " << modul << endl;
}
void Vec3d :: scal(Vec3d& lhs, Vec3d& rhs)
{
    double scal = rhs.x*lhs.x + rhs.y* lhs.y + rhs.z*lhs.z;
    std:: cout << "a * b = " << scal << std::endl;
}
std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x << separator << y << separator << z << rightBrace;
    return ostrm;
}
std::istream& Vec3d::readFrom(std::istream& istrm)
{
    char leftBrace(0), comma(0), rightBrace(0);
    double xv(0), yv(0), zv(0);
    istrm >> leftBrace >> xv >> comma >> yv >> comma >> zv >> rightBrace;
    if (istrm.good())
    {
        if ((Vec3d:: separator == comma) && (Vec3d:: x = xv) && (Vec3d:: y = yv))
            x=xv, y=yv, z=zv;
    }
    else
    {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
}

