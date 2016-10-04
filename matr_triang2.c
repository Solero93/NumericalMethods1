#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 0
#define FALSE -1

int resoltrisup (int n, double **a, double *b, double tol);
int gauss (int n, double **a, double *b, double tol);
		

// Funció main que demana totes les dades necessáries per fer els cálculs
int main() {
	double **a, *b, tol;
	int n, count, count2, retu, retu2;

	printf("Diguim el tamany de la matriu i la toleráncia: ");
	scanf("%d %lf",&n,&tol);

	b = malloc(sizeof(double)*n);
	
	printf("posi b amb els coeficients separats : ");		
	
	for (count = 0; count < n; count++) {
		scanf("%lf",&b[count]);
	}
	printf("\n");
	a = malloc(sizeof(double*)*n);

	for (count = 0; count < n; count++) {
		printf("Diguim la %d. vector fila de la matriu : ",(count+1));
		a[count] = malloc(sizeof(double)*n);
		
		for (count2 = 0; count2 < n; count2++) {
			scanf("%lf",&a[count][count2]);
		}
	}
	printf("\n");

	retu2 = gauss( n , a, b , tol) ;
	retu = resoltrisup( n, a, b, tol );


	if (retu == TRUE && retu2 == TRUE) {
		printf("El sistema té solució\n");
	} else {
		printf("El sistema no té solució calculable per aquest programa");
	}

		
return 0;
}
/* 	n -> dimensió de la matriu
	a -> matriu triangular superior
	b -> vector de termes independents
	tol -> toleráncia, és a dir, valor a partir del cual diem que un element és equivalent a 0 */

int resoltrisup (int n, double **a, double *b, double tol) {
	int i, j;

	for (i = n-1; i >= 0; i--) {
		if (fabs(a[i][i]) <= tol) {
			return -1; 
		}
		b[i] = b[i] / a[i][i];
		for (j = 0; j < i; j++) {
			b[j] = b[j] - ( a[j][i] * b[i] );
		}
	}
	for (i = 0; i < n; i++) {
		printf("%f ", b[i]);
	}
	printf("\n");

	for (i=0 ; i<n ; i++) {
		for (j=0; j<n; j++) {
			printf("%3.f ", a[i][j]); 
		}
		printf("\n");
	}
	
	return 0;
}

/*
pertot k = 1,2...n-1
	pertot i = k+1, k+2,..., n
		m(i,k) = a(i,k) / a(k,k)  » m(i,k) = a(i,k) , així no agafem memòria extra
		pertot j = k+1, k+2, ... , n
			a(i,j) = a(i,j) - m(i,k)*a(k,j)
		b(i) = b(i) - m(i,k)*b(k)

aixo es gauss
*/

int gauss(int n, double **a, double *b, double tol) {
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
			b[i] = b[i] - a[i][k] * b[k];
		}
	}	
	return 0;	
}



/*  CACA!!!
#define N 30

double a[N][N] , b[N]

llegir n
if( n > N ) { return 1; ...........

*/
