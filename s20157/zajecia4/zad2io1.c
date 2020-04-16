#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	
	int i;
	int tab [11];
	FILE *plik;
	plik = fopen(argv[1],"r");
	if (plik == NULL){
		perror("Brak pliku\n");
		return 1;
	}
	
	else
	{
		for (i = 0; feof(plik)==0; i++){
		if(feof(plik)){
			printf("Koniec pliku\n");
			break;
		}
		fscanf(plik, "%d", &tab[i]);
}
}
	fclose(plik);
	for (i = 10; i >= 0; i--){
		printf("%d ", tab[i]);
	}

	return 0;

}

