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
int main()
{
    using namespace std;
    comparison(1/1,1/1);
    return 0;
}
