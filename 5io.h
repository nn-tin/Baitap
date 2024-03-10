#include "5read.h"
#include "5fraction.h"

#define NMax 50

typedef struct {fraction Array[NMax]; int N;} fractionarray;

void input(fractionarray* A);
void output(fractionarray A);
void NegativeFractionArray(fractionarray A, fractionarray* B);