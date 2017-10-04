#include "complex.h"
#include <iostream>
#include <sstream>
bool testParse(const std::string& str) //добавить возведение в степень
{
    using namespace std; 

    istringstream istrm(str); // istringstream(str) - преобразование str в число
    Complex z;
    istrm >> z;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();
}
void Comparison(Complex one, Complex two)
{
    using namespace std;
    Complex z1(one);
    Complex z2(two);
    cout << "--------Comparison--------" << endl;
    if (z1 == z1) // сравнение
    {
       cout << z1 << "==" << z2 <<endl;
    }
    else cout << z1 << "!=" << z2 <<endl;
}
void Arithmetic(Complex one, Complex two)
{
    using namespace std;
    Complex z1(one);
    Complex z2(two);
    Complex z3;
    cout << "--------Arithmetic--------" << endl;
    cout << "Complex vs Complex:" << endl;
    z3 = z1 + z2;
    cout << z1 << "+" << z2 << "=" << z3 << endl;
    z3 = z1 - z2;
    cout << z1 << "-" << z2 << "=" << z3 << endl;
    z3 = z1 * z2;
    cout << z1 << "*" << z2 << "=" << z3 << endl;
    z3 = z1 / z2;
    cout << z1 << "/" << z2 << "=" << z3 << endl << endl;

    cout << "Complex vs double:" << endl;
    double z4 = 5;
    z3 = z1 + z4;
    cout << z1 << "+" << z4 << "=" << z3 << endl;
    z3 = z1 - z4;
    cout << z1 << "-" << z4<< "=" << z3 << endl;
    z3 = z1 * z4;
    cout << z1 << "*" << z4 << "=" << z3 << endl;
    z3 = z1 / z4;
    cout << z1 << "/" << z4 << "=" << z3 << endl << endl;

    cout << "Double vs complex:" << endl;
    double z5 = 10;
    z3 = z5 + z2;
    cout << z5 << "+" << z2 << "=" << z3 << endl;
    z3 = z5 - z2;
    cout << z5 << "-" << z2 << "=" << z3 << endl;
    z3 = z5 * z2;
    cout << z5 << "*" << z2 << "=" << z3 << endl;
    z3 = z5 / z2;
    cout << z5 << "/" << z2 << "=" << z3 << endl << endl;
}
void testParse_()
{
    using namespace std;
    cout << "--------TestParse---------" << endl;
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
    cout << endl;

}
int main() 
{
    using namespace std;
    Comparison({ 0.5, 1.5 }, { 0.5, 1.5 });
    Arithmetic({ 1,2 }, { 3,4 });
    testParse_();
    system("pause");
    return 0;
}