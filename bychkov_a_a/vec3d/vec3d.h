#ifndef VEC3D_10
#define VEC3d_10

#include <iosfwd>
class Vec3d
{
public:
    Vec3d()=default;
    Vec3d(const double xv, const double yv, const double zv);
    Vec3d(const Vec3d& v);
    Vec3d& operator=(const Vec3d& v);
    bool operator==(const Vec3d& lhs) const;
    bool operator!=(const Vec3d& lhs) const;
    Vec3d& operator+=(const Vec3d& rhs);
    Vec3d& operator-=(const Vec3d& rhs);
    Vec3d& operator*=(const Vec3d& rhs);
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
    static void leng(Vec3d& lhs, Vec3d& rhs);
    static void scalar(Vec3d& lhs, Vec3d& rhs);
};
std::ostream& operator << (std::ostream& ostrm, const Vec3d& rhs);
std::istream& operator >> (std::istream& istrm, const Vec3d& rhs);

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);

Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);

Vec3d operator*(const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator*(const Vec3d& lhs, const double rhs);
Vec3d operator*(const double lhs, const Vec3d& rhs);
#endif
