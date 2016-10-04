// Practica 2: Errors

#include <stdio.h>
#include <math.h>

int main(void) {
	double x, result1, result2, result3, precision;
	
	/*x -> nombre sobre el qual treballar
	 result1 -> resultat al fer sinh(x)
	 result2 -> resultat al fer (exp(x)-exp(-x))/2
	 result3 -> resultat al fer taylor 
	 precision -> precisió del resultat al 3r metode */

	printf("Sinh de? : ");
	scanf("%f",x);
	if (x < -1 || x > 1) { // si és de valor incorrecte imprimim missatge d'error i terminem programa
		printf("El nombre donat no té sinh");
		return 0;
	}
	result1 = sinh(x); // calculem el 1r resultat
	
	result2 = (exp(x)-exp(-x))/2; //calculem el 2n resultat

	precision = 1.e-15; //definim la precisió de l'exemple
	result3 = taylor_sinh(x,precision); // calculem el 3r resultat
	
	printf("%f %f %f",result1,result2,result3); // imprimim tots

return 0;
}

// funció auxiliar per poder efectuar el 3r cálcul
double taylor_sinh(double x, double precision) {
	double elem, quadrat, tmp_x, elem_next; 
	int count_fact = 4, fact = 6; // comptador pel factorial del denominador de la fracció, i el valor del factorial
	
	elem = x; // inicialitzem el 1r element amb x
	quadrat = x*x; // definim el quadrat d'x per reduir el nombre d'operacions
	tmp_x = x*quadrat; // el valor del numerador de la fracció actual
	elem_next = elem + tmp_x/fact; // calculem el segon element a partir del primer

	do {
		if (abs(elem_next - elem) >= precision) {
			return elem_next; // si arribem a la precisió que volíem, retornem l'element
		}
	}
	while (abs(elem_next - elem) >= precision) {	
		tmp_x *= quadrat;
		fact *= (count_fact)*(count_fact+1);
		count_fact+=2; // fem els cálculs necessaris per tal de reduir el nombre d'operacions necessáries

		elem = elem_next; // intercanviem l'element actual
		elem_next += tmp_x / fact; // calculem el següent
	}
	return elem_next; // retornem 
}
