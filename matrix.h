//
// Created by 97903 on 2020/12/5.
//

#ifndef MATRIXOPERATION_MATRIX_H
#define MATRIXOPERATION_MATRIX_H
#include <iostream>
using namespace std;
class Matrix {
private:
    float* pointer;
    int length;
    int width;
    bool origin = false;
public:
    Matrix();
    Matrix(float* pointer, int length, int width);
    ~Matrix();
    friend ostream& operator<<(ostream& os, const Matrix& out);
    Matrix& operator=(const Matrix& b);
    Matrix& operator*(const Matrix& a);
    Matrix& operator*(float a);
    Matrix& operator+(const Matrix& b);
    Matrix& operator-(const Matrix& b);
    friend Matrix& operator*(float a,Matrix& b);


};
#endif //MATRIXOPERATION_MATRIX_H
