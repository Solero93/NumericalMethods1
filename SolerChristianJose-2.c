#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 0
#define FALSE -1

// Practica 2

void hilbert(int n, double** a);
void identitat_p(int n, double** a, double p);
void palu (int n, double **a, double **l, double**u);
void sumar_matrius(int n, double** a, double** b);
int gauss(int n, double **a, double tol);
void multiplicacio (int n, double **a, double **b);
void printmatriu(int n, double **a);

int main() {
	double **h, **i, **l, **u, p = 0.68;
	int valor;
	l = malloc(sizeof(double*)*(4));
	u = malloc(sizeof(double*)*(4));	
	h = malloc(sizeof(double*)*(4));
	i = malloc(sizeof(double*)*(4));

	hilbert(4,h);
	identitat_p(4,i,p);
	sumar_matrius(4,h,i);
	printf("A es: ");
	printmatriu(4,h);
	valor = gauss(4,h,1.e-7);
	if (valor == FALSE) {
		return -1;
	}
	palu(4,h,l,u);
	printf("L es: ");
	printmatriu(4,l);
	printf("U es: ");
	printmatriu(4,u);
	
	multiplicacio(4,u,l);
	printf("UL es: ");
	printmatriu(4,u);


return 0;
}

void identitat_p(int n, double** a, double p) {
        int i, j;
        for (i = 0; i < n; i++) {
                a[i] = malloc(sizeof(double)*(n));
               	for (j = 0; j < i; j++) {
			a[i][j] = 0;
		}
		a[i][i] = p;
		for (j = i+1; j <n; j++) {
			a[i][j] = 0;
		}
        }
}

void hilbert(int n, double** a) {
        int i, j;
        for (i = 0; i < n; i++) {
		a[i] = malloc(sizeof(double)*(n));
                for (j = 0; j < n; j++) {
                        a[i][j] = 1./(j+i+1);
                }
        }
}

void sumar_matrius(int n, double** a, double** b) {
	int i,j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			a[i][j] = a[i][j] + b[i][j];
		}
	}
}


void palu (int n, double **a, double **l, double**u) {
        int i, j;
        for (i = 0; i < n; i++) {
                l[i] = malloc(sizeof(double)*(n));
                u[i] = malloc(sizeof(double)*(n));
                for (j = 0; j < i; j++) {
                        l[i][j] = a[i][j];
                        u[i][j] = 0;
                }
                l[i][i] = 1;
                u[i][i] = a[i][i];
                for (j = i+1; j < n; j++) {
                        l[i][j] = 0;
                        u[i][j] = a[i][j];
                }
        }
}

void multiplicacio (int n, double **a, double **b) {
	int i,j,k;
	double tmp;
	for (i=0; i<n; i++) {
		tmp = 0;
		for (j=0; j<n; j++) {
			for (k=0; k<n; k++) {
				tmp += a[i][j]*b[k][j]; 	
			}
		a[i][j] = tmp;
		}
	}
}

int gauss(int n, double **a, double tol) {
        int i, j, k;

        for (k=0; k < n-1; k++) {
                if (fabs(a[k][k]) < tol) {
                	return -1;
                }
                for (i=k+1; i < n; i++) {
                        a[i][k] = a[i][k] / a[k][k];
                        for (j=k+1; j < n; j++) {
                                a[i][j] = a[i][j] - a[i][k] * a[k][j];
                        }
                }
        }
        return 0;
}

void printmatriu(int n, double **a) {
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
		printf("%.4f ",a[i][j]);
		} printf("\n");
	}
}
