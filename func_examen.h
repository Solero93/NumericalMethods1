#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 0
#define FALSE -1

int resoltrisup (int n, double **a, double *b, double tol);
int gauss (int n, double **a, int *p, double tol);
void palu (int n, double **a, double **l, double **u);
double horner(double* poli, int len, double x);
int pivot_parcial(int n, int k, double **a, int *p, double tol);
int random_matriu (int n, double **a, double tol);
void hilbert (int n, double **m);
double calcul_norma_matrix (int n, double **m);
double calcul_norma_vector (int n, double *v);
double error_alea (double u);


int resoltrisup (int n, double **a, double *b, double tol) {
        int i, j;

        for (i = n-1; i >= 0; i--) {
                if (fabs(a[i][i]) < tol) {
                        return -1; 
                }
                b[i] = b[i] / a[i][i];
                for (j = 0; j < i; j++) {
                        b[j] = b[j] - (a[j][i] * b[i]);
                }
        }
	return 0;

}

int gauss(int n, double **a, int *p, double tol) {
        int i, j, k;

        for (k=0; k < n-1; k++) {
                if (fabs(a[k][k]) < tol) {
                        if (pivot_parcial(n,k,a,p,tol) == FALSE) {
                                return -1;
                        }
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
        int i, fila=k, tmp_p;
        double max=0, *tmp_a;

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

                p[n] = (p[n]+1) % 2;
        }
        return 0;
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

double horner(double* poli, int len, double x) {
        int count;
        double r = 0;

        for (count = 0; count <= len; count++) {
                r = poli[count] + x * r;
        }

        return r;
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

double calcul_norma_matrix(int n, double **m) {
        double norma = 0, norm_tmp;
        int i, j;
        for (i = 0; i < n; i++) {
                norma += fabs(m[0][i]);
        }
        for (i = 1; i < n; i++) {
                for (j = 0; j < n; j++) {
                        norm_tmp += fabs(m[i][j]);
                }
                if (norm_tmp > norma) {
                        norma = norm_tmp;
                }
        }
        return norma;
}

double calcul_norma_vector(int n, double *v) {
        double norma = fabs(v[0]), tmp;
        int i;
        for (i = 1; i < n; i++) {
		tmp = fabs(v[i]);
                if (norma < tmp) {
                        norma = tmp;
                }
        }
        return norma;
}

double error_alea(double u) {
        srand(time(NULL));
        return (u * (2 * (double)rand()/RAND_MAX-1));
}                   
