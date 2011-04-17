#include "include/Matrix.h"
#include <iostream>
#include <algorithm>

void matPrint(Matrix<double> mat)
{
    for(unsigned int i = 0; i < mat.rows(); ++i)
    {
        for(unsigned int ii = 0; ii < mat.cols(); ++ii)
        {
            std::cout << mat(i, ii) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    try
    {

    Matrix<double>* mat = new Matrix<double>(3,3);
    mat->insert(0, 0, 3);
    matPrint(*mat);

    }
    catch(std::exception& e)
    {
       std::cout << e.what() << std::endl;
    }
    return 0;
}
