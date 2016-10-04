#include <stdio.h>
#include <stdlib.h>

double horner(double* polinome, int length, double x);

int main(void) {
	int 
	n, // número de variables 
	count1, // contador1
	count2; // contador2
	
	double 
	*z, // vector de coeficients reals entrats
	*polinome, // el polinomi resultant
	tmp, // variable temporal
	mult;

	// demano escanejo etc.
	printf("Diguim un nombre natural > 0 : ");
	scanf("%d", &n);
	if (n <= 0) {
		printf("Error inválid. El programa sortirá.");
		return 0;
	}
	z = malloc(sizeof(double)*(n));
	for (count1 = 0; count1 < n; count1++) {
		printf("Digui'm un nombre real: \n");
		scanf("%f",&z[count1]);
	}
	
	// vector polinomio resultante 
	polinome = malloc(sizeof(double)*(n+2));
	
	polinome[0] = 1; // primer elemento de la sucesión
	polinome[1] = -z[0]; // segundo elemento de la sucesión

	// bucle para cada valor de z (alias ir multiplicando) 
	for (count1 = 1; count1 < n; count1++) {
		for (count2 = count1+1; count2 >= 1; count2--) {
	 		tmp = polinome[count2];
			polinome[count2] = tmp - (polinome[count2-1] * z[count1]);
		}
	}
	for (count1 = 0; count1 <= n; count1++) {
		printf("%f, ", polinome[count1]);
		printf("\n");
	}

	printf("Entra un número: \n");
	scanf("%f",&mult);
	
	printf("El polinomi evaluat amb Horner dóna %f\n",horner(polinome,n,mult));

return 0;
}

double horner(double* poli, int len, double x) {
	int count;
	double r=0;

	for (count=0; count <= len; count++) {
		r = poli[count] + x * r;
	}
	
	return r;	
}
