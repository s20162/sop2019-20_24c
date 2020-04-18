#include <stdlib.h>
#include <stdio.h>

int main() {
	int sum = 0;
	int i = 0;
	char koniec;
	printf("Jesli bedziesz chciał zakonczyc, nacisnij [q] a potem enter\n\n");
	do{
		sum += i;
		printf("Podaj liczbe:\n"); scanf("%d", &i);
		koniec = getchar();
	} while (koniec != 'q');

	return sum;
}

