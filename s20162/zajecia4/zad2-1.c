#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    
    int n=0;
    int m=0;
    int i=0;
    int tab[20];
    FILE *inputfile;

    if((inputfile = fopen(argv[1], "r"))) {
        fscanf(inputfile, "%d", &n);
        for( i=0; i<n; i++) {
            fscanf(inputfile, "%d", &tab[i]);
        }
        fclose(inputfile);
        for( i=n-1; i>=0; i--) {
            printf("%d \n", tab[i]);
        }
    } else {
        printf("podaj ile liczb chcesz wprowadzić\n");
        scanf("%d", &n);
        printf("podaj %d liczby\n", n);
        m=n;
        while(m>0) {            
            scanf("%d", &tab[i]);
            i++;
            m--;
        }
        printf("ciag w odwrotnej kolejnosci\n");
         for( i=n-1; i>=0; i--) {
            printf("%d \n", tab[i]);
        }

    }

    return 0;
}