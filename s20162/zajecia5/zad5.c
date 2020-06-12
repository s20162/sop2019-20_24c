#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char** argv) {

    if (argc<2)
    {
        return 1;
    }   

    int limit = atoi(argv[1]);
    int sum=0;
    int i;
    int j;

    if (fork())
    {
        wait(NULL);
        for (i=0; i<=limit; i++) {
            sum+= i;
        }
        printf("wynik sumowania liczb od 0 do %d to %d\n", limit, sum);

    } else {
        for (j=1; j<=limit; j+=2) {
            printf("%d  ", j);
        }
        printf("\n");
    }

    return 0;
}