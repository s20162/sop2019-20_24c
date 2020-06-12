#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char** argv) {

    printf("PID %d, PPID %d\n", getpid(), getppid());

    return 0;
}