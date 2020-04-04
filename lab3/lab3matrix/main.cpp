#include <iostream>

#include "matrix.h"

using namespace std;

int main() {
    //Matrix
    double array1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat1(array1);
    double array2[3][3] = {{1,2,3}, {2,2,2}, {2,2,2}};
    Matrix mat2(array2);
    Matrix mat3 = mat1 * 2.65;
    cout << endl << "Result of multiplication:" << endl;
    mat3.printMatrix();

    Matrix mat4;
    cout << endl << "Enter the elements of the matrix:" << endl;
    mat4.readMatrix();
    Matrix mat5;
    cout << endl << "Enter the elements of the second matrix:" << endl;
    mat5.readMatrix();
    Matrix mat6;
    mat6 = mat4 * mat5;
    cout << endl << "The result of multiplication of two entered matrices:" << endl;
    mat6.printMatrix();

    mat6 = mat6 - mat4;
    cout << endl << "The result of subtraction:" << endl;
    mat6.printMatrix();





    return 0;

}


