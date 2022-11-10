#include "eval-perf.h"
#include <iostream>
#include <x86intrin.h>
#include <chrono>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>


int* MatrixTrans_naif(int* mat, int* matTransposee, size_t tailleColonne, size_t tailleLigne)
{
    for (size_t i = 0; i < tailleColonne; i++) {
        for (size_t j = 0; j < tailleLigne; j++) {
            matTransposee[j * tailleLigne + i] = mat[i * tailleLigne + j];
        }
    }
    return matTransposee;
}

int** MatrixTrans_block(int** mat, int** matTransposee, size_t tailleColonne, size_t tailleLigne, int b)
{

    for (size_t I = 0; I < tailleColonne; I += b) {
        for (size_t J = 0; J < tailleLigne; J += b) {
            int i_fin = std::min(I+b, tailleColonne);
            int j_fin = std::min(J+b, tailleLigne);

            for (size_t i = I; i < i_fin; i++) {
                for (size_t j = J; j < j_fin; j++) {
                    matTransposee[j][i] = mat[i][j];
                }
            }
        }
    }

    return matTransposee;
    
}

/*void MatrixTrans obliv(size t m, size t n, const double* A, size t sa, double * B, size t sb) {

}*/

int main() {
    int N = 511;
  EvalPerf PE;

    //Qu4
    int* A1 = new int[9];
    A1[0] = 1;
    A1[1] = 2;
    A1[2] = 3;
    A1[3] = 4;
    A1[4] = 5;
    A1[5] = 6;
    A1[6] = 7;
    A1[7] = 8;
    A1[8] = 9;

    int* matTranspose1 = new int[9];

    int* A4 = new int[128];
    int cpt3 = 1;
    for(int i = 0; i < 128; i++){
        A4[i] = cpt3;
        cpt3++;
    }

    int* matTranspose4 = new int[128];


    //Qu5
    int** A2 = new int*[3];
    int cpt1 = 1;
    for(int i = 0; i < 3; i++){
        A2[i] = new int[3];
        for(int j = 0; j < 3; j++){
            A2[i][j] = cpt1;
            cpt1++;
        }
    }

    int** matTranspose2 = new int*[3];
    for(int i = 0; i < 3; i++){
        matTranspose2[i] = new int[3];
    }

    int** A3 = new int*[64];
    int cpt2 = 1;
    for(int i = 0; i < 64; i++){
        A3[i] = new int[2];
        for(int j = 0; j < 2; j++){
            A3[i][j] = cpt2;
            cpt2++;
        }
    }

    int** matTranspose3 = new int*[64];
    for(int i = 0; i < 64; i++){
        matTranspose3[i] = new int[2];
    }

    /*int** A5 = new int*[32];
    int cpt4 = 1;
    for(int i = 0; i < 32; i++){
        A5[i] = new int[4];
        for(int j = 0; j < 4; j++){
            A3[i][j] = cpt4;
            cpt4++;
        }
    }

    int** matTranspose5 = new int*[32];
    for(int i = 0; i < 32; i++){
        matTranspose5[i] = new int[4];
    }

    int** A6 = new int*[16];
    int cpt5 = 1;
    for(int i = 0; i < 16; i++){
        A6[i] = new int[8];
        for(int j = 0; j < 8; j++){
            A6[i][j] = cpt5;
            cpt5++;
        }
    }

    int** matTranspose6 = new int*[16];
    for(int i = 0; i < 16; i++){
        matTranspose6[i] = new int[8];
    }*/

PE.start();

    /*int* B1 = MatrixTrans_naif(A1, matTranspose1, 3, 3);
    for (int i = 0; i < 9; i++) {
        std::cout << B1[i] << std::endl;
    }*/

    //int* B4 = MatrixTrans_naif(A4, matTranspose4, 64, 64);
    /*for (int i = 0; i < 128; i++) {
        std::cout << B4[i] << std::endl;
    }*/

    /*int** B2 = MatrixTrans_block(A2, matTranspose2, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << B2[i][j] << std::endl;
        }
    }*/

    int** B3 = MatrixTrans_block(A3, matTranspose3, 64, 2, 128);

    //int** B5 = MatrixTrans_block(A5, matTranspose5, 32, 4);

    //int** B6 = MatrixTrans_block(A6, matTranspose6, 16, 8);
    

  PE.stop();

  std::cout << "nbr cycles: " << PE.cycles() << std::endl;
  std::cout << "nbr secondes: " << PE.seconds() << std::endl;
  std::cout << "nbr millisecondes: " << PE.millisecond() << std::endl;
  std::cout << "CPI = " << PE.CPI(N) << std::endl;
  std::cout << "IPC = " << PE.IPC(N) << std::endl;

  return 0;
}

