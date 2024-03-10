#include <stdio.h>
#include "5fraction.h"

int NegativeFraction(fraction A) {
    if (A.Numerator * A.Denominator < 0) return 1;
    return 0;
}