//
// Created by Александр on 07.11.2017.
//
#include "matrixR.h"
#include "matrixU.h"
#include <cstdlib>


using namespace std;
int main()
{
    int a=3, b=3;
    MatrixR matrixR(a,b);
    for(ptrdiff_t i(0); i<a; i++)
    {
        for (ptrdiff_t j(0); j<b;j++)
        {
            matrixR.at(i,j)=rand();
        }
    }
    return 0;
}

