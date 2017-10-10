#include "vec3d.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

Vec3d::Vec3d(const double xv, const double yv, const double zv) 
    :x(xv), y(yv), z(zv) {}

Vec3d::Vec3d(const Vec3d& v) 
    :x(v.x), y(v.y), z(v.z) {}
Vec3d& Vec3d::operator=(const Vec3d& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
bool Vec3d:: operator==(const Vec3d& rhs) const
{
    return ((abs(rhs.x - x) < e) && (abs(rhs.y - y) < e) && (abs(rhs.z - z) < e));
}
bool Vec3d::operator!=(const Vec3d& rhs)const
{
    return !operator==(rhs);
}
std::ostream& operator << (std::ostream& ostrm, const Vec3d& rhs)
{
    return rhs.writeTo(ostrm);
}
std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
{
    return rhs.readFrom(istrm);
}
Vec3d& Vec3d:: operator+=(const Vec3d& rhs)
{
       x += rhs.x;
       y += rhs.y;
       z += rhs.z;
       return *this;
}    
 Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs)
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
Vec3d& Vec3d:: operator*=(const Vec3d& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
}
Vec3d operator*(const Vec3d& lhs, const Vec3d& rhs)
{
    Vec3d mult(lhs);
    mult *= rhs; 
    return mult; 
}
/*Vec3d operator*(const double lhs, const Vec3d& rhs)
{
    Vec3d mult(rhs);
    mult *= lhs;
    return mult;
}
Vec3d operator*(const Vec3d& lhs, const double rhs)
{
    Vec3d mult(lhs);
    mult *= rhs;
    return mult;
}*/
void angle_between_vector(const Vec3d& lhs, const Vec3d& rhs)
{
    using namespace std;
    double angle = acos((rhs.x*lhs.x + rhs.y*lhs.y + rhs.z*lhs.z) /
        (sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z)*(sqrt(lhs.x*lhs.x + lhs.y*lhs.y + lhs.z*lhs.z))));
    cout << setprecision(2) << angle << endl;
}
void leng(const Vec3d& lhs, const Vec3d& rhs) // длина
{
    using namespace std;
    double leng_ = sqrt(pow(rhs.x - lhs.x, 2) + pow(rhs.y - lhs.y, 2) + pow(rhs.z - lhs.z, 2));
    cout << setprecision(2) << leng << endl;
}
void scalar(const Vec3d& lhs, const Vec3d& rhs)
{
    using namespace std;
    double i = lhs.y*rhs.z - lhs.z*rhs.y;
    double j = lhs.x*rhs.z - rhs.x*lhs.z;
    double k = lhs.x*rhs.y - rhs.x*lhs.y;
    double modul = sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));
    cout << "a x b = " << "(" << i << ")i + (" << -j << ")j + (" << k << ")k" << endl;
    cout << "|a x b| = " << modul << endl;
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
    istrm >> leftBrace >> xv >> separator >> yv >> separator >> zv >> rightBrace;
    if (istrm.good())
    {
        if (Vec3d::separator == comma)
        {
            x = xv;
            y = yv;
            z = zv;
        }
        /*else
        {
            istrm.setstate
        }*/
    }
    return istrm;
}
