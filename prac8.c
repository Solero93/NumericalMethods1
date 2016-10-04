#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
1. Pedir valores y derivadas
2. Interpolar por Hermite -> mismo que Newton pero con el primer paso distinto
3. Evaluar polinomio en un punto
4. Evaluar derivada del polinomio en un punto
*/

int difdivherm(double *x, double *f, int m);
double horner_pol(double z, double* x, double* c, int n);
double horner_der(double z, double* x, double* c, int n);
void nodes(int n, double a, double b, double* x);

int main(void){
	double *x, *f;
	
	x = malloc(sizeof(double)*(2n+2));
	f = malloc(sizeof(double)*(2n+2));

	

	free(x);
return 0; 	
}

void nodes(int n, double a, double b, double* x){
         int i;
         double h, t;
                h = (b-a)/n;
		for (i=0; i<n; i++){
			x[i] = a+i*h;
		}
}

double horner(double z, double* x, double* c, int n) {
        int i;
	double p = c[n-1];
        for (i = n-2; i>=0; i--){
                p = p*(z-x[i])+c[i];
        }
        return p;
}
