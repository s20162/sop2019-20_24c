#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    
    int n=0;
    int i=0;
    
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.bin", "wb");
    int *tab = (int*)calloc(n, sizeof(int));
    char *tab_char;
    long fileSize;

    fscanf(inputfile, "%d", &n);

    for( i=0; i<n; i++){
        fscanf(inputfile, "%d", tab+i);
    }
    fclose(inputfile);
    for( i=n-1; i>=0; i--) {
        printf("%d \n", *(tab+i));
    }
    
    fwrite(tab, sizeof(int), n, outputfile);
    fclose(outputfile);

    outputfile = fopen("output.bin", "rb");
    fseek(outputfile, 0L, SEEK_END);
    fileSize = ftell(outputfile);
    fseek(outputfile, 0L, SEEK_SET);

    if(argc>1 && !strcmp(argv[1],"--print")) {
        tab_char = (char*)calloc(fileSize/sizeof(char), sizeof(char));
        fread(tab_char, sizeof(char), fileSize/sizeof(char), outputfile); 
        fclose(outputfile);
        for( i=0; i<fileSize/sizeof(char); i++) {
            printf("%d", *(tab_char+i));
        }
        printf("\n");
        free(tab_char);
       
    }
    free(tab);
    

    return 0;
}