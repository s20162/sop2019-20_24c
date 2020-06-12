#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char** argv) {

    int a;
    printf("PID %d, PPID %d\n", getpid(), getppid());
    scanf("%d", &a);
   

    return 0;
}