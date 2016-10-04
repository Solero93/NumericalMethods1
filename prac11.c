#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double eval_pol(double* poli, int n, double x);
double eval_polder(double* poli, int n, double x);
double new_rap (double *x, double prec, int iter);
double secant (double *x, double prec, int iter);

int main(void){
	int n = 2;
	double *x;
	
	x = malloc(sizeof(double)*(n+1));
	
	free(x);
return 0;	
}

double eval_pol(double* poli, int n, double x) {
        int count;
        double r = 0;

        for (count = 0; count <= n; count++) {
                r = poli [count] + x * r;
        }
        return r;
}

double eval_polder(double* poli, int n, double x) {
        int count;
        double r = 0;

        for (count = 0; count < n; count++) {
                r = poli[count] * (n-count) + x * r;
        }
	return r;
}

double new_rap (double *x, double prec, int iter) {
	double x0, x1;
	int n=0;
	while (fabs(x0-x1) > prec && iter < n) {
		x1 = x0 - (f(x0) / f'(x0));
		n++;
	}
	return x1;	
}

double secant (double *x, double prec, int iter) {
	double x0, x1, x2;
	int n=0
	while (fabs(x0-x1) > prec && iter < n) {
		x2 = x1 - f(x1)*((x1) - (x0)) / (f(x1) - f(x0));
		x0 = x1;
		x1 = x2;
		n++;	
	}
	return x2;
}
