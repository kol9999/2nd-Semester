#include "matrix.h"
#include <iostream>

using namespace std;

void Matrix::allocateSpace() {
    mat = new double*[Height];
    for(int i = 0; i < Height; i++) {
        mat[i] = new double[Width];
    }
}

void Matrix::deallocateSpace() {
    for(int i = 0; i < Height; i++) {
        delete [] mat[i];
    }
    delete [] mat;
}

Matrix::Matrix() {
    allocateSpace();
}

Matrix::Matrix(const double (&mat)[3][3]) {
    allocateSpace();
    for(int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            this->mat[i][j] = mat[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocateSpace();
}

void Matrix::readMatrix() {
    for(int i = 0; i < Height; i++) {
        for(int j = 0; j < Width; j++) {
            cout << "λ" << i + 1 << j + 1 << "= ";
            cin >> mat[i][j];
        }
    }
}

void Matrix::printMatrix() const {
    for(int i = 0; i < Height; i++) {
        for(int j = 0; j < Width; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix& Matrix::operator* (const Matrix &other) {
    Matrix* multiplication = new Matrix();
    for(int i = 0; i < Height; i++) {
        for(int j = 0; j < Width; j++) {
            multiplication->mat[i][j] = 0;
            for(int k = 0; k < Width; k++) {
                multiplication->mat[i][j] += this->mat[i][k] * other.mat[k][j];
            }
        }
    }
    return *multiplication;
}

Matrix& Matrix::operator* (const double &real) {
    Matrix* multiplication = new Matrix();
    for(int i = 0; i < Height; i++) {
        for(int j = 0; j < Width; j++) {
            multiplication->mat[i][j] += this->mat[i][j] * real;
        }
    }
    return *multiplication;
}

Matrix& Matrix::operator+ (const Matrix &other) {
    Matrix* addition = new Matrix();
    for(int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            addition->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *addition;
}

Matrix& Matrix::operator- (const Matrix &other) {
    Matrix* subtraction = new Matrix();
    for(int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            subtraction->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *subtraction;
}

bool Matrix::operator== (const Matrix &other) {
    for(int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            if (this->mat[i][j] != other.mat[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!= (const Matrix &other) {
    for(int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            if (this->mat[i][j] != other.mat[i][j])
                return true;
        }
    }
    return false;
}

double Matrix::determinant() const {
    return this->mat[0][0] * ((this->mat[1][1] * this->mat[2][2]) - (this->mat[2][1] * this->mat[1][2])) -
    this->mat[0][1] * ((this->mat[1][0] * this->mat[2][2]) -
    (this->mat[2][0] * this->mat[1][2])) + this->mat[0][2] * ((this->mat[1][0] * this->mat[2][1]) -
    (this->mat[2][0] * this->mat[1][1]));
}

bool Matrix::operator< (const Matrix &other) {
    double determinant = this->determinant();
    double otherDeterminant = other.determinant();
    return determinant < otherDeterminant;
}

bool Matrix::operator> (const Matrix &other) {
    double determinant = this->determinant();
    double otherDeterminant = other.determinant();
    return determinant > otherDeterminant;
}



