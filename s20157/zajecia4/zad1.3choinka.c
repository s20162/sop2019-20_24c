#include <stdlib.h>
#include <stdio.h>

void draw(int height);
	
int main (int argc, char **argv){

int height = atoi(argv[1]);
draw(height);

return 0;
}

void draw(int height){
	int NumOfStars, NumOfSpaces;
	int i; 
	int j;
	for (i = 1; i <= height; i++){
		NumOfStars = 2 * i - 1; 	
		NumOfSpaces = height - i;
		for (j=0; j < NumOfSpaces; j++){
			printf(" ");
		}
		for (j = 0; j < NumOfStars; j++){
			printf("*");
		}
		printf("\n");
	}
}
