//
// Created by 97903 on 2020/12/5.
//
#include "matrix.h"
#include <iostream>
#include <iomanip>
Matrix::Matrix() {
    pointer = NULL;
    length = 0;
    width = 0;
}
Matrix::Matrix(float* pointer, int length, int width):pointer(pointer),length(length),width(width)
{
    origin = true;
}

ostream& operator<<(ostream& os, const Matrix& out) {
    for (int i = 0; i < out.length; i++) {
        for (int j = 0; j < out.width; j++) {
            os << setw(13) << left << setfill(' ') << out.pointer[i * out.length + j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix& Matrix::operator=(const Matrix &b) {
    pointer = b.pointer;
    length = b.length;
    width = b.width;
    origin = false;
    return *this;
}


Matrix& Matrix::operator*(const Matrix &b) {
    int ma = length,mb = b.length,na = width,nb = b.width;
    float* ans = new float[ma * nb]{ 0 };
    for (int i = 0; i < ma; i++) {
        for (int j = 0; j < nb; j++) {
            for (int k = 0; k< na; k++) {
                ans[i * nb +j] += pointer[i* na+k] * b.pointer[k* nb+j];
            }
        }
    }
    Matrix *answer = new Matrix(ans,ma,nb);
    return *answer;
}

Matrix& operator*(float a, Matrix &b) {
    float* ans = new float[b.width*b.length];
    int count = 0;
    for (int i = 0; i < b.length; i++) {
        for (int j = 0; j < b.width; j++) {
            ans[count] = a*b.pointer[count];
            count++;
        }
    }
    Matrix *answer = new Matrix(ans,b.length,b.width);
    return *answer;
}

Matrix& Matrix::operator*(float a) {
    float* ans = new float[width*length];
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            ans[count] = pointer[count]*a;
            count++;
        }
    }
    Matrix *answer = new Matrix(ans,length,width);
    return *answer;
}

Matrix& Matrix::operator+(const Matrix &b) {
    float* ans = new float[width*length];
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            ans[count] = pointer[count]+b.pointer[count];
            count++;
        }
    }
    Matrix *answer = new Matrix(ans,length,width);
    return *answer;
}
Matrix& Matrix::operator-(const Matrix &b){
    float* ans = new float[width*length];
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            ans[count] = pointer[count]-b.pointer[count];
            count++;
        }
    }
    Matrix *answer = new Matrix(ans,length,width);
    return *answer;
}

Matrix::~Matrix() {
    if(origin) {
        delete[] pointer;
    }
}

