#include "5fraction.h"
#include <iostream>


int readf(fraction* A) {
    char s[100];
    if (fgets(s, sizeof(s) - 1, stdin) == NULL) return -1;
    if (sscanf(s, "%d/%d", &A->Numerator, &A->Denominator) != 2) return -2;
    return 0;
}

int readi(int* N) {
    char s[4];
    if (fgets(s, sizeof(s) - 1, stdin) == NULL) return -1;
    if (sscanf(s, "%d", N)) return -2;
    return 0;
}