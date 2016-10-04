#include <stdio.h>
#include <math.h>

void main() {
	float a,b,c;
	int [] result;

	printf("digui'm els tres coeficients de l'equació\n");
	printf("primer: ");
	scanf("%f", &a);
	printf("segon: ");
	scanf("%f", &b);
	printf("tercer: ");
	scanf("%f", &c);

	result = solve_2grade_eq(a,b,c);
	printf(result[0] + "\n");
	printf(result[1] + "\n");


int[] solve_2grade_eq(float a, float b, float c) {
	int[] result = int [2];
	int[0] = -b + sqrt((b^2)-4*a*c);
	int[1] = -b - sqrt((b^2)-4*a*c);
	return result;
}

}
