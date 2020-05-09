#include <stdlib.h>
#include <stdio.h>

int main()
{
	int sum = 0;
	int liczba;
	char koniec;
	do{
		printf("Podaj liczbe do zsumowania\n");
		scanf("%d", &liczba);
		sum += liczba;
		printf("Suma wynosi: %d\n", sum);
		printf("\nJesli chcesz zakonczyc, nacisnij [q] a potem enter\n\n");
		koniec = getchar();
		liczba=0;
		if(koniec == 'q'){
			break;
		}
		
	}
	while (koniec != 'q');
	return 0;
}
