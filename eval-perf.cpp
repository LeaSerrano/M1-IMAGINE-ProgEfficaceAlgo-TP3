#include "eval-perf.h"
#include <iostream>
#include <x86intrin.h>
#include <chrono>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

double* mat2vec(size_t n , const double* A , double* y , double* tmp , size_t k, double* v){
    for(int i = 0;i < n;++i) {
        for (int j = 0 ; j < n ; j+=k) {
            tmp[i] += A[i*n+j]*v[j];
        }
    }

    for (int i = 0 ;i < n ; ++i) {
        for (int j = 0 ; j < n ; j+=k) {
            y[i] += A[i*n+j]*tmp[j] ;
        }
    }
    return y;

}

double* mat2tvec(size_t n , const double* A , double* y , double* tmp , size_t k, double* v){
    for(int i = 0;i < n;++i) {
        for (int j = 0 ; j < n ; j+=k) {
            tmp[i] += A[j*n+j]*v[j];
        }
    }

    for (int i = 0 ;i < n ; ++i) {
        for (int j = 0 ; j < n ; j+=k) {
            y[i] += A[i*n+j]*tmp[j] ;
        }
    }
    return y;

}

int main() {
    int n, N;
  EvalPerf PE;
  
    //Ex16
    double* A = new double[16];
    A[0] = 1;
    A[1] = 1;
    A[2] = 1;
    A[3] = 1;
    A[4] = 1;
    A[5] = 1;
    A[6] = 1;
    A[7] = 1;
    A[8] = 1;
    A[9] = 1;
    A[10] = 1;
    A[11] = 1;
    A[12] = 1;
    A[13] = 1;
    A[14] = 1;
    A[15] = 1;

    double* v = new double[4];
    v[0] = 2;
    v[1] = 2;
    v[2] = 2;
    v[3] = 2;

    double* y = new double[4];

    double* tmp = new double[4];

    size_t k = 1;

PE.start();
  
    double* test = mat2vec(4, A, y, tmp, k, v);
    for (int i = 0; i < 4; i++) {
        std::cout << test[i] << std::endl;
    }

    double* test2 = mat2tvec(4, A, y, tmp, k, v);
    for (int i = 0; i < 4; i++) {
        std::cout << test2[i] << std::endl;
    }

  PE.stop();

  std::cout << "nbr cycles: " << PE.cycles() << std::endl;
  std::cout << "nbr secondes: " << PE.seconds() << std::endl;
  std::cout << "nbr millisecondes: " << PE.millisecond() << std::endl;
  std::cout << "CPI = " << PE.CPI(N) << std::endl;
  std::cout << "IPC = " << PE.IPC(N) << std::endl;

  return 0;
}

