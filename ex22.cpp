#include "eval-perf.h"
#include <iostream>
#include <x86intrin.h>
#include <chrono>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>


void counting_sort_naif(int * C, int * R, int T[5], size_t n, size_t min , size_t max) {

    //Voir dans le main
    
}

int main() {
    int N = 128;
  EvalPerf PE;

  //Qu 1
  //int T[] = {1, 6, 3, 1, 3};

  int T[128];
  for (int i = 0; i < 128; i++) {
        T[i] = i;
  }

  int n = 128;

  size_t min = 1;
  size_t max = T[n-1];

  int* R = new int[n];
  //std::cout << n << std::endl;
  int* C = new int[max+1];
  for (int i = 0; i < max+1; i++) {
    C[i] = 0;
  }

  int nbC = max+1;
   int cpt = 0;

  //Qu 2
  int m;
  if (n >= 128) {
    m = 2;
  }
  else {
    m = std::min(4, n);
  }

  int* BInput = new int[n];
  int* B = new int[max+1];

  int nbB = max+1;
  int cpt2 = 0;

    int q;



PE.start();

    //J'ai ajouté les fonctions directement ici, car si je les déplace dans des fontion alors je ne peux pas faire de for (int x : T)

   //counting_sort_naif
   /*for (int x : T) {
        C[x] += 1;
   }

   for (int i = 0; i < nbC; i++) {
      for(int j = 0; j < C[i]; j++) {
           R[cpt] = i;
           cpt++;
      }
    }*/

    /*for (int i = 0; i < 5; i++) {
        std::cout << R[i] << std::endl;
    }*/


    //couting_sort_bucket
    for (int x : T) {
        q = m*x;
        B[q] += 1;
    }

    for (int i = 0; i < nbB; i++) {
        for(int j = 0; j < B[i]; j++) {
            BInput[cpt2] = i;
            cpt2++;
        }
    }

    /*for (int i = 0; i < 5; i++) {
        std::cout << BInput[i] << std::endl;
    }*/
    

  PE.stop();

  std::cout << "nbr cycles: " << PE.cycles() << std::endl;
  std::cout << "nbr secondes: " << PE.seconds() << std::endl;
  std::cout << "nbr millisecondes: " << PE.millisecond() << std::endl;
  std::cout << "CPI = " << PE.CPI(N) << std::endl;
  std::cout << "IPC = " << PE.IPC(N) << std::endl;

  return 0;
}

