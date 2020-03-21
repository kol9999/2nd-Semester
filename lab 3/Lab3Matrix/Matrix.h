#include <iostream>

using namespace std;

#ifndef RABOTA3_MATRIX_H
#define RABOTA3_MATRIX_H


class Matrix {
private:
    double** mat;
    double determinant() const;
    void allocateSpace();
    void deallocateSpace();
public:
    Matrix();
    Matrix(double const (&mat)[3][3]);
    ~Matrix();
    const static int Height = 3;
    const static int Width = 3;
    void readMatrix();
    void printMatrix() const;
    Matrix& operator* (const Matrix &other);
    Matrix& operator* (const double &real);
    Matrix& operator+ (const Matrix &other);
    Matrix& operator- (const Matrix &other);
    bool operator== (const Matrix &other);
    bool operator!= (const Matrix &other);
    bool operator< (const Matrix &other);
    bool operator> (const Matrix &other);
};


#endif //RABOTA3_MATRIX_H
