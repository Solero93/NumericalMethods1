#include <stdio.h>
#include <math.h>

int main(void) {
	float x, y;
	int count_x = 0, count_y = 60;
	
	x = (M_E - 1);
	while (count_x <= 29) {
		x = M_E - ((count_x + 1) * x);
		count_x += 1;
		printf ("%f \n",x);
	}

	printf("separa\n\n\n\n\n");

	y = 0;
	while (count_y >= 31) {
		y = (M_E - y) / count_y;
		count_y -= 1;
		printf ("%f \n",y);
	}
	printf("separa\n\n\n\n\n");
	printf ("%f %f \n",x,y);
	
return 0;
}
