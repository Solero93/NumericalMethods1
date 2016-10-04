#include "../metodes/func_examen.h"

//gcc arxiu.h -c -Wall -lm

int main() {
	double **a;
	int i, j;
	a = malloc(sizeof(double*)*3);
	hilbert(3,a);
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("%e",a[i][j]);
		}
	}
return 0;
}
