#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    
    int n=0;
    int i=0;
    
    FILE *inputfile = fopen("input.txt", "r");

    fscanf(inputfile, "%d", &n);
    int *tab = (int*)calloc(n, sizeof(int));

    for( i=0; i<n; i++) {
    fscanf(inputfile, "%d", tab+i);
    }
    fclose(inputfile);
    for( i=n-1; i>=0; i--) {
        printf("%d \n", *(tab+i));
    }

    
    free(tab);

    return 0;
}