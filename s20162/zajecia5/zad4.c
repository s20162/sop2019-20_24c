#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char** argv) {

    if (fork())
    {
        printf("Rodzic PPID %d, PID %d\n", getppid(), getpid());
        printf("Rodzic czeka\n");
        wait(NULL);
        printf("Rodzic wznowił prace\n");

    } else {
        sleep(2);
        printf("Dziecko PPID %d, PID %d\n", getppid(), getpid());
        printf("dziedcko skonczyło pracowac\n");
    }

    return 0;
}