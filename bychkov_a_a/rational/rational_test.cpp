//
// Created by Александр on 16.10.2017.
//
#include "rational.h"
#include <iostream>
#include <sstream>
/*bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    c
    Rational R;
    if (istrm.good())
    {
        cout << "Correct:" << str << "--->" << R << endl;
    }
    else
    {
        cout << "Incorrect" << str << "--->" << R << endl;
    }
    return istrm.good();
}*/
void comparison(Rational a, Rational b)
{
    Rational a_(a), b_(b);
    if (a_==b_)
    {
        std::cout << a_ << "=" << b_ << std::endl;
    } else std::cout << a_ << "!=" << b_ << std::endl;
}
void operations(Rational a, Rational b)
{
    using namespace std;
    Rational a_(a), b_(b);
    cout << "a+b = " << a_+b_<<endl;
    cout << "a-b = " << a_-b_<<endl;
    cout << "a*b = " << a_*b_ << endl;
    cout << "a/b = " << a_*b_ << endl;
}
int main()
{
    using namespace std;
    cout << "---------Comparison----------" << endl;
    //comparison(1/2, 1/3);
    //comparison(13/15,13/15);
    Rational a_={1/2}, b_={3/4};
    if (a_==b_)
    {
        std::cout << a_ << "=" << b_ << std::endl;
    } else std::cout << a_ << "!=" << b_ << std::endl;
    //cout << "---------Operations----------" << endl;
    //cout << "a=" << a << " , b=" << b << endl;
    //operations(a,b);
    return 0;
}
