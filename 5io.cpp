#include "5io.h"
#include "5read.h"
#include <iostream>

using namespace std;

void input(fractionarray* A) {
    printf("Nhap N: "); readi(&A->N);
    for (int i = 0; i < A->N; i++) {
        printf("Nhap phan so thu %d: ", i); readf(&A->Array[i]);
    }
}

void output(fractionarray A) {
    for (int i = 0; i < A.N; i++) {
        printf("Phan so thu %d: %d/%d\n", i, A.Array[i].Numerator, A.Array[i].Denominator);
    }
}

void NegativeFractionArray(fractionarray A, fractionarray* B) {
    for (int i = 0; i < A.N; i++) {
        if (NegativeFraction(A.Array[i])) {
            B->Array[B->N] = A.Array[i];
            (B->N)++;
        }
    }
}