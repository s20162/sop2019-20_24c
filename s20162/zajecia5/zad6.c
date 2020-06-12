#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    int i;

   for ( i = 0; i < 10; i++) {
       pid_t forkpid = fork();
       if (i==9 && forkpid==0)
       {
           sleep(30);
       }
       if (forkpid>0) /* rodzic */
       {
           wait(NULL);
           break;
       }
    }
   

    return 0;
}