#include <iostream>
#include <iomanip>
#include <thread>
#include "matrix.h"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"


int main() {
    cout<<RESET;
    printf("Enter the length of Matrix A(\"length\" \"width\"):");
    int ma; int na;
    cin >> ma; cin >> na;
    float* matrixA = new float[ma * na];
    printf("Enter the Matrix A line by line:\n");
    for (int i = 0; i < ma; i++) {
        for (int j = 0; j < na; j++) {
            cin >> matrixA[i * na + j];
        }
    }
    cout<<BLUE << ("Matrix A input complete:\n");
    Matrix a(matrixA,ma,na);
    cout<<a;
    cout << RESET;
    printf("Enter the length of Matrix B:(\"length\" \"width\"):");
    int mb, nb;
    cin >> mb; cin >> nb;
    float* matrixB = new float[mb * nb];
    printf("Enter the Matrix B line by line:\n");
    for (int i = 0; i < mb; i++) {
        for (int j = 0; j < nb; j++) {
            cin >> matrixB[i * nb + j];
        }
    }
    cout <<BLUE<< ("Matrix B input complete:\n");
    Matrix b(matrixB,mb,nb);
    cout<<b;
    cout << RESET;
    if (na != mb) {
        cout <<RED<< "Wrong length!Please cheack carefully" << endl;
        cout << RESET;
    }
    else {
        Matrix ans ;
        ans = (a*b);
        cout <<YELLOW<< "-------------------------------\nComplete!The answer matrix is:\n";
        cout << RESET;
        cout<<ans;
    }
}
