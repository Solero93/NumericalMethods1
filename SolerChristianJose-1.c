#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 0
#define FALSE -1

//</b> JoséSoler
// Examen de MNU1
// Exercici 1

double recurrencia(double y0, int n, double a);
int comprova(double y, int n, double a);


int main() {
	double a = 8.74, y;	
	int valor;

	y = log((1+a)/a);
	y = recurrencia(y, 20, a);
	printf("El valor numero 20 es: %.10lf",y);
	valor = comprova(y, 20 ,a);
	if (valor == TRUE) {
		printf("Ho es");
	}
	else {
		printf("No ho es");
	}
return 0;
	
}

double recurrencia1(double y, int n, double a) {
	int i;
	for (i=1; i<n; i++) {
		y = ((1./n) - (a*y));
	}
	return y;
}

double recurrencia2(double y, int n, double a) {
	int i;
	for (i=1; i<n; i++) {
		
	}

int comprova(double y, int n, double a) {
	if ((1./((a+1)*(n+1))) <= y && y <= (1./(a*(n+1)))) {
		return 0;
	} return -1;
}
