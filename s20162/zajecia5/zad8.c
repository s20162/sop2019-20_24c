#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    FILE *f;
    char buff[100];

    if(fork()) {
        wait(NULL);
        sleep(1);
        f = fopen("plik", "r");
        fgets(buff, 100, (FILE*)f);
        printf("%s\n",buff);


    } else {
        f = fopen("plik", "w+");
        fprintf(f, "moja wiadomosc do wyswietlenia")  ;
        fclose(f);
        }
}