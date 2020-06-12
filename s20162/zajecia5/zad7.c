#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    int i;
    pid_t masterPid = getpid();

   for ( i = 0; i < 10; i++) {
       pid_t forkpid = fork();
       if (forkpid == 0) {
           break;
       }
    }
    if (getppid() == masterPid) {
        printf("dziecko zaczyna czekac\n ");
        sleep(30);
        printf("dziecko sie konczy\n");
    }
    if (getpid() == masterPid) {
        printf("Master zaczyna czekac\n");
        wait(NULL);
        printf("Master zaczyna pracowac\n");
    }
    
       
    return 0;
}