#include <stdlib.h>
#include <stdio.h>

void printHexLineinC(unsigned int offset, char *buffer, int ElementsRead);

int main(int argc, char **argv){
	
	
	FILE *plik;
	plik = fopen(argv[1],"r");
	if (plik == NULL){
		printf("Brak pliku\n");
		return 1;
	}
	
	else
	{	
		fseek(plik, 0, SEEK_END);
		unsigned int FileSize = ftell(plik);
		fseek(plik, 0, SEEK_SET);
		
		char buffer[16];
		unsigned int offset = 0L;
		
		
		while(offset<FileSize){
			
			size_t ElementsRead = fread(buffer, sizeof(char), 16, plik);
			
		if(ElementsRead == 0){
			printf("Blad pliku w offsecie: %08X\n", offset);
		}
		offset += ElementsRead;
		printHexLineinC(offset, buffer, ElementsRead);
	}
	

}
	fclose(plik);
	return 0;
}

void printHexLineinC(unsigned int offset, char *buffer, int ElementsRead){
	printf("%08X   ", offset);
	int i = 0;
	
	for(i = 0; i < ElementsRead; i++){
		unsigned int number = (unsigned char) buffer[i];
		printf("%02X ", number);
	}
	
	for(i = 16; i > ElementsRead; i--){
		printf("   ");
	}	
	char validatorchar = ' ';	
	for(i = 0; i < ElementsRead; i++){
		unsigned char wc = (unsigned char) buffer[i];
		if(i==0){
			printf("|");
		}
		if(wc < validatorchar){
			wc='.';
		}
		printf("%c", wc);
	}
	printf("|\n");
}
			
		
	



