#include <malloc.h>
#include <iostream>

using namespace std;

typedef struct { int numer, deno; } frac;

ostream& operator<< (ostream& outDev, const frac& F){
	if (F.numer == 0 || F.deno == 1) outDev << F.numer;
	else outDev << F.numer << "/" << F.deno;
	return outDev;
}

istream& operator>> (istream& inDev, frac& F){
	inDev >> F.numer >> F.deno;
	return inDev;
}

void insertFraction(frac*& Fa, int& N, frac F) {
	int M = N + 1;
	frac* Fa1 = (frac*) realloc(Fa, M*sizeof(frac));
	if (Fa1 != NULL) {
		Fa1[N] = F;
		N++;
		Fa = Fa1;
	}
}

int iFraction(frac* F) {
	char Buff[100] = { 0 };
	fgets(Buff, 99, stdin);
	int readVariable = sscanf_s(Buff, "%d/%d", &(F->numer), &(F->deno)) ; 
	return readVariable;
}

void iFractionArray(frac*& Fa, int& N) {
	frac F;
	Fa = NULL; N = 0;
	for (int i = 0; ; i++) {
		cout << "Nhap phan so thu " << i + 1 << ": ";
		if (iFraction(&F)) insertFraction(Fa, N, F);
		else return;
	}
}

void oFractionArray(frac Fa[], int N) {
	for (int i = 0; i < N; i++) {
		cout << Fa[i] << "\t";
	}
	cout << "\n";
}


void deleteLastFraction(frac*&Fa, int &N) {
	int M = N - 1;
	frac* Fa1 = (frac*) malloc(M*sizeof(frac));
	if (Fa1 != NULL) {
		for (int i = 0; i < M; i++) Fa1[i] = Fa[i];
		N = M;
		free(Fa);
		Fa = Fa1;
	}
}

int main() {

	frac* Fa; int N;

	cout << "Phan so co dinh dang a/b. Nhap Ctrl + X de dung.\n";

	cout << "Nhap mang phan so:\n";
	iFractionArray(Fa, N);

	cout << "Mang phan so sau khi nhap:\n";
	oFractionArray(Fa, N);

	frac F;

	cout << "Nhap phan so them vao: ";
	iFraction(&F);
	insertFraction(Fa, N, F);
	cout << "Mang phan so sau khi them:\n";
	oFractionArray(Fa, N);

	deleteLastFraction(Fa, N);
	cout << "Mang phan so sau khi xoa phan tu cuoi:\n";
	oFractionArray(Fa, N);

	free(Fa);

	return 0;

}