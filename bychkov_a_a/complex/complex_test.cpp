#include "complex.h"
#include <iostream>
#include <sstream>
bool testParse(const std::string& str) // нужно сделать правильное сравнение + добавить возведение в степень + сложение разных типов
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
int main()
{
    using namespace std;

    Complex z = Complex(1.2,2);
    if (z == Complex(1, 2)) // сравнение
    {
        std::cout << z << "==" << Complex(1,2 ) << std::endl;
    }
    else std::cout << z << "!=" << Complex(1, 2) << std::endl;
    if (z == Complex(2, 0)) 
    {
        std::cout << z << "==" << Complex(2, 0) << std::endl;
    }
    else std::cout << z << "!=" << Complex(2, 0) << std::endl;
    z = Complex(5, 0);
    cout << endl;

    cout << "Complex vs Complex:" << endl;
    Complex z1 = Complex(2, 4);
    Complex z2 = Complex(4, 8);
    z = z1 + z2;
    cout << z1 << "+" << z2 << "=" << z << endl;
    z = z1-z2;
    cout << z2 << "-" << z2 << "=" << z << endl;
    z = z1 * z2;
    cout << z1 << "*" << z2 << "=" << z << endl;
    z = z1 * z2;
    cout << z1 << "/" << z2 << "=" << z << endl << endl;

    cout << "Complex vs double:" << endl;
    Complex z3 = Complex(5, 10);
    double z4 = 5;
    z = z3 + z4;
    cout << z3 << "+" << z4 << "=" << z << endl;
    z = z3 - z4;
    cout << z3 << "-" << z4 << "=" << z << endl;
    z = z3 * z4;
    cout << z3 << "*" << z4 << "=" << z << endl;
    z = z3 / z4;
    cout << z3 << "/" << z4 << "=" << z << endl << endl;

    cout << "Double vs complex:" << endl;
    Complex z5 = Complex(10, 5);
    double z6 =7;
    z = z6 + z5;
    cout << z6 << "+" << z5 << "=" << z << endl;
    z = z6 - z5;
    cout << z6 << "-" << z5 << "=" << z << endl;
    z = z6 * z5;
    cout << z6 << "*" << z5 << "=" << z << endl;
    z = z6 / z5;
    cout << z6 << "/" << z5 << "=" << z << endl<<endl;


    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
    system("pause");
    return 0;
}