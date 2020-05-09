#include <stdlib.h>
#include <stdio.h>

	
int main (int argc, char **argv){
	int HEIGHT = atoi(argv[1]);
	int i, j;
	for (i = 1; i <= HEIGHT-1; ++i){
		for (j = 0; j < HEIGHT-i; ++j)
			printf(" ");
		
		for (j = 0; j < 2*i-1; ++j)
			printf("*");
		
		printf("\n");
	}

	for (i = 1, j = 0; j < HEIGHT-i; ++j)
		printf(" ");

	printf("*\n");
	
	return 0;
}


