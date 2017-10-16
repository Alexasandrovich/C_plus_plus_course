//
// Created by Александр on 16.10.2017.
//
#include "vec3d.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
void equal(Vec3d a, Vec3d b)
{
    Vec3d a_(a), b_(b);
    if (a_==b_)
    {
        std:: cout << a_ << " = " << b_ << std::endl;
    }
    else
    {
        std:: cout << a_ << " != " << b_ << std::endl;
    }
}
void operations(Vec3d a, Vec3d b)
{
    using namespace std;
    Vec3d a_(a),b_(b);
    Vec3d x = a_;
    x*=10;
    cout << "a+b= " << a_+b_<<endl;
    cout << "a-b= " << a_-b_<<endl;
    cout << "a*10=" << x << endl;
}
int main()
{
    using namespace std;
    cout << "---------Comparison---------"<< endl;
    equal({1,2,3.56}, {1,2,3.55});
    equal({1.44,2.34, 34}, {1.44,2.34, 34});
    cout << "---------Functions and operations---------"<<endl;
    Vec3d z1 = {1,2,3};
    Vec3d z2 = {4,5,6};
    cout << "a=" << z1 << ", b=" << z2<< endl;
    Vec3d::angle_between_vector(z1, z2);
    Vec3d::leng(z1);
    Vec3d::leng(z2);
    Vec3d::vector(z1, z2);
    Vec3d::scal(z1, z2 );
    operations(z1,z2);
    return 0;
}
