#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 0
#define FALSE -1

int gauss (int n, double **a, int *p, double tol);
void pivot_parcial (int n, int k, double **a, int *p);
void palu (int n, double **a, double **l, double **u);

// Funció main que demana totes les dades necessáries per fer els cálculs
int main() {
	double **a, **l, **u, tol;
	int n, count, count2, retu, *p;

	printf("Diguim el tamany de la matriu i la toleráncia: ");
	scanf("%d %lf",&n,&tol);

	p = malloc(sizeof(int)*(n+1));

	for (count = 0; count < n; count++) {
		p[count] = count;
	}
	p[n] = 0;
	
	a = malloc(sizeof(double*)*n);

	for (count = 0; count < n; count++) {
		printf("Diguim la %d. vector fila de la matriu : ",(count+1));
		a[count] = malloc(sizeof(double)*n);
		
		for (count2 = 0; count2 < n; count2++) {
			scanf("%lf",&a[count][count2]);
		}
	}
	printf("\n");

	retu = gauss(n, a, p, tol) ;	

	if (retu == TRUE) {
		printf("La matriu factoritza\n");
		l = palu_l (n, a);	
		printf("xorra");
		u = palu_u (n, a);
	} else {
		printf("El sistema no té solució calculable per aquest programa");
	}
	
	free(a);
	free(p);
		
return 0;
}
/* 	n -> dimensió de la matriu
	a -> matriu triangular superior
	b -> vector de termes independents
	tol -> toleráncia, és a dir, valor a partir del cual diem que un element és equivalent a 0 */

int gauss(int n, double **a, int *p, double tol) {
	int i, j, k;

	for (k=0; k < n-1; k++) {
		if (pivot_parcial(n,k,a,p,tol) == FALSE) {
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

int pivot_parcial(int n, int k, double **a, int *p, double tol) {
	int i, fila = k, tmp_p;
	double max = 0, *tmp_a;

	for (i = k; i < n; i++) {
		if (fabs(a[i][k]) > max) {
			max = a[i][k];
			fila = i;
		}
	}
	if (max < tol) {
		return -1;
	}
	if (i != k) {
		tmp_a = a[fila];
		a[fila] = a[k];
		a[k] = tmp_a;

		tmp_p = p[i];
		p[i] = p[k];
		p[k] = tmp_p;
			
		p[n] += (p[n] + 1) % 2;
	}
	return 0;
}
		
void palu (int n, double **a, double **l, double **u) {
	int i, j;
	for (i=0; i<n; i++) {
		l[i] = malloc(sizeof(double)*(n));		
		u[i] = malloc(sizeof(double)*(n));
		for (j=0; j<i; j++) {
			l[i][j] = a[i][j];
			u[i][j] = 0;
		}
		l[i][i] = 1;
		u[i][i] = a[i][i];
		for (j=i+1; j<n; j++) {
			l[i][j] = 0;
			u[i][j] = a[i][j];
		}
	}
}
