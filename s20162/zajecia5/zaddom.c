#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    int i;
    pid_t masterPid = getpid();
    for ( i = 0; i < 2; i++) {
       pid_t forkpid = fork();
       if (forkpid == 0) {
           break;
       }
    }
    if (getppid() == masterPid) {
        printf("dziecko zaczyna czekac\n ");
        sleep(10);
        printf("dziecko sie konczy\n");
    }
    if (getpid() == masterPid) {
        printf("Master zaczyna czekac\n");
        wait(NULL);
        printf("Master zaczyna pracowac\n");
    }
    pid_t childMasterPid = getpid();

    for ( i = 0; i < 2; i++) {
       pid_t childforkpid = fork();
       if (childforkpid == 0) {
           break;
       }
    }
    if (getppid() == childMasterPid) {
        printf("dziecko dziecka zaczyna czekac\n ");
        sleep(30);
        printf("dziecko dziecka sie konczy\n");
    }
    if (getpid() == childMasterPid) {
        printf("child Master zaczyna czekac\n");
        wait(NULL);
        printf("child Master zaczyna pracowac\n");
    }

   
       
    return 0;
}