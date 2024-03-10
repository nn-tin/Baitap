#include "5io.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    fractionarray A = { {0} , 0 };
    fractionarray B = { {0} , 0 };
    input(&A);
    NegativeFractionArray(A, &B);
    printf("Mang phan so ban dau: \n");
    output(A);
    printf("Mang phan so am: \n");
    output(B);

    return 0;
}