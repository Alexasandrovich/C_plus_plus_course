//
// Created by Александр on 15.10.2017.
//
#include "vec3dT.h"
template <typename T>
void Comparison(Vec3dT<T> a, Vec3dT<T> b)
{
    using namespace std;
    Vec3dT<T> v1(a);
    Vec3dT<T> v2(b);
    if (v1 == v2) {
        cout << v1 << "==" << v2 << endl;
    } else cout << v1 << "!=" << v2 << endl;
}
template <typename T>
void operations(Vec3dT<T>& a, Vec3dT<T>& b)
{
    using namespace std;
    Vec3dT<T> a_(a),b_(b);
    Vec3dT<T> x = a_;
    x*=10;
    cout << "a+b= " << a_+b_<<endl;
    cout << "a-b= " << a_-b_<<endl;
    cout << "a*10=" << x << endl;
}
int main()
{
    using namespace std;
    Vec3dT<double> z1= {1,2,3};
    Vec3dT<double> z2={3,1,2};
    cout << "--------Comparison--------" << endl;
    Vec3dT<double> z3= {1.55,2.6,3.12};
    Vec3dT<double> z4= {1.55,2.6,3.12};
    Comparison(z1,z2);
    Comparison(z3,z4);
    cout << "--------Functions and operations--------" << endl;
    Vec3dT<double> z5= {5.3,6.2,7.1};
    Vec3dT<double> z6= {1.6,2.1,3.1};
    cout << "a=" << z5 << " , b=" << z6<< endl; //????????
    //operations<double>(z5,z6);
    Vec3dT<double>::angle_between_vector(z5, z6);
    Vec3dT<double>::leng(z5);
    Vec3dT<double>::leng(z6);
    Vec3dT<double>::vector(z5, z6);
    Vec3dT<double>::scal(z5, z6 );
    return 0;
}