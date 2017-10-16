//
// Created by Александр on 16.10.2017.
//

#ifndef VEC3D_10_10_2017
#define VEC3D_10_10_2017

#include <iosfwd>
struct Vec3d
{
public:
    Vec3d()=default;
    Vec3d(const double xv, const double yv, const double zv);
    Vec3d(const Vec3d& v);
    bool operator==(const Vec3d& lhs) const;
    bool operator!=(const Vec3d& lhs) const;
    bool operator=(const Vec3d& rhs);
    //bool operator>(const Vec3d& rhs);
    //bool operator<(const Vec3d& lhs);
    Vec3d& operator+=(const Vec3d& rhs);
    Vec3d& operator-=(const Vec3d& rhs);
    Vec3d& operator*=(const double rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
public:
    double e = 1E-6;
    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };
    static const char leftBrace{ '{' };
    static const char rightBrace{ '}' };
    static const char separator{ ',' };
    static void angle_between_vector(Vec3d& lhs, Vec3d& rhs);
    static void leng(Vec3d& lhs);
    static void vector(Vec3d& lhs, Vec3d& rhs);
    static void scal(Vec3d& lhs, Vec3d& rhs);
};
std::ostream& operator << (std::ostream& ostrm, const Vec3d& rhs);
std::istream& operator >> (std::istream& istrm, const Vec3d& rhs);

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);

Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);

#endif