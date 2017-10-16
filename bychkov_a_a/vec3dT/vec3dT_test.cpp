//
// Created by Александр on 15.10.2017.
//
#include "vec3dT.h"
#include <iostream>
#include <sstream>
#include <cmath>
void Comparison(Vec3dT a, Vec3dT b)
{
    using namespace std;
    Vec3dT v1(a);
    Vec3dT v2(b);
    cout << "--------Comparison--------" << endl;
    if (v1 == v2)
    {
        cout << v1 << "==" << v2 <<endl;
    }
    else cout << v1 << "!=" << v2 <<endl;
}
int main()
{
    using namespace std;
    Comparison({1,2,3},{3,1,2});
    return 0;
}