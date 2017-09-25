#include "complex.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
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

    Complex z;
    cout << "the original z: " << z << endl;
    z += Complex(2.0);
    cout << z << " added 2 " << endl;
    z -= Complex(3.0, -4);
    cout << z << " subtracted 3-4i "<< endl;
    z *= 2;
    cout << z << " multiplied by 2 " << endl;
    cout << "Input Examples" << endl;
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
    system("pause");
    return 0;
}