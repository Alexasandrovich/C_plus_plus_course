//
// Created by Александр on 24.10.2017.
//

#include "kvanternion.h"
#include <iomanip>
void Equal(Kvanternion a, Kvanternion b)
{
    using namespace std;
    Kvanternion a_(a), b_(b);
    if(a_==b_)
    {
        cout << a_ << "==" << b_ << endl;
    }
    else cout << a_ << "!=" << b_ << endl;
}
void Operations(Kvanternion a, Kvanternion b)
{

    using namespace std;
    Kvanternion a_(a),b_(b);
    cout << "a+b= " << a_+b_<<endl;
    cout << "a-b= " << a_-b_<<endl;
    cout << "a*b=" << a_*b_ << endl;
}
int main()
{
    using namespace std;
    Kvanternion a = {10,20,30,40};
    Kvanternion b= {15,25,35,45};
    cout << "---------Comparison---------"<< endl;
    cout << "a=" << a<<endl;
    cout << "b=" << b<<endl;
    Equal({4,5,6.1,1},{4,5,6,1});
    cout << "---------Functions and operations---------"<<endl;
    Operations(a,b);
    Kvanternion::determenant(a);
    Kvanternion::inverse_kvanternion(b);
    return 0;
}

