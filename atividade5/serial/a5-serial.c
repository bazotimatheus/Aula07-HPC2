#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int circle_count = 0, n_points = 1e+9, i;
	double pi, erro;
	double x, y, tmp;

	srand(time(NULL));

	for(i = 1; i < n_points; i++) {
		x = ((rand() % 200)/ 100.0) - 1;
		y = ((rand() % 200)/ 100.0) - 1;
		tmp = x*x + y*y;
		if(tmp <= 1) circle_count++;
	}

	pi = 4.0 * circle_count / n_points;
	erro = fabs(M_PI - pi);

	printf("\nValor obtido de PI: %lf", pi);
	printf("\nValor de PI (math.h): %lf", M_PI);
	printf("\nErro: %lf\n\n", erro);
}