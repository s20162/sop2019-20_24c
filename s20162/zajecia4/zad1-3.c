#include <stdlib.h>
#include <stdio.h>

void draw(int height);

int main(int argc, char **argv) {
    
    int height = atoi(argv[1]);
    draw(height);

    return 0;
}

void draw(int height) {
    
    int i,j,k;

    for( i=0; i<height; i++ ) {
        for( j=0; j<height-i-1; j++) {
            printf(" "); 
        }
        for( k=0; k<2*i+1; k++) {
            printf("*"); 
        }
        printf("\n");
    }
}