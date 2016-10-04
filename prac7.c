#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double horner(double z, double* x, double* c, int n);
int difdiv(double *x, double *f, int n);
void nodes(int n, double a, double b, double* x, int ind);
double fun(double* x, int ind);

int main(){
	double *x, error;
	int ind;
	
	printf("Digui l'indicador(0 o 1): ");
	scanf("%d",&ind);

	x = malloc(sizeof(double)*(1000));
	
	error = fun(x,ind);
	if (error == -1) {
		printf("Hi ha hagut un error en les dades");
	} else {
		printf("L'error és: %f",error); 
	}
	free(x);

return 0;
}

double horner(double z, double* x, double* c, int n) {
	int i;
	double p = c[n-1];
	for (i = n-2; i>=0; i--){
		p = p*(z-x[i])+c[i];
	}
	return p;
}

int difdiv(double *x, double *f, int n) {
	int i, k;
	double tol = pow(10,-12);
	for (k=1; k<=n; k++){
		for (i=n-1; i>k-1; i--){
			if (fabs(x[i] - x[i-k]) < tol) {
				return -1;
			}
			f[i] = (f[i]-f[i-1]) / (x[i]-x[i-k]);
		}
	} return 0;
}

void nodes(int n, double a, double b, double* x, int ind){
	int i;
	double h, t;
	switch(ind) {
	case 0:	
		h = (b-a)/n;
		for (i=0; i<n; i++){
			x[i] = a+i*h;
		}
	break;
	
	case 1:
		for (i=0; i<n; i++){
			t = cos( (M_PI_2 * ((2*i)+1)) / (n+1)) ;
			x[i] = a + ((b-a)/2) *(t+1);
		}
	break;
	}
}

double fun(double* x, int ind) {
	double *f,*p, max_error = 0., tmp_max;
	int i, n=1000;

	f = malloc(sizeof(double)*(n));
	p = malloc(sizeof(double)*(n));

	switch(ind) {
	case 0:
		nodes(n,-1,1,x,0);
		for (i=0; i<n; i++){
			f[i] = pow(x[i],6);
			p[i] = f[i];
		} break;
	case 1:
		nodes(n,-1,1,x,0);
		for (i=0; i<n; i++){
			f[i] = exp(x[i]);
			p[i] = f[i];
		} break;
	case 2:		
		nodes(n,0,1,x,0);
		for (i=0; i<n; i++){
			f[i] = exp(-1./pow(x[i],2));
			p[i] = f[i];
		} break;
	case 3:	
		nodes(n,0,1,x,0);
		for (i=0; i<n; i++){
			f[i] = fabs(x[i]);
			p[i] = f[i];
		} break;
	case 4:
		nodes(n,0,1,x,0);
		for (i=0; i<n; i++){
			f[i] = 1./(1+pow(x[i],2));
			p[i] = f[i];
		} break;
	}
	
	if (difdiv(x,p,n) == -1) { return -1; }	
	
	for (i=0; i<n; i++) {
		tmp_max = fabs(f[i]-horner(p[i],x,p,n));
		if (tmp_max > max_error) {
			max_error = tmp_max;
		}
	}
	return max_error;
}
