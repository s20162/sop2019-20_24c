#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char **argv){

	int i;
	pid_t PID;

printf("Proces programu: %d\n", getpid());



for (i = 0; i< 100; i++){	
switch(PID = fork()){
	
	case -1:
	printf("Error in fork\n");

	case 0:
	printf("#%d Jestem potomkiem, moj PID wynosi: %d\n",i, getpid());
	exit(0);
	
}
}	
for ( i = 0; i < 100; i++){
	wait(0);
	}
	
	printf("\t\tJestem RODZICEM, moj PID wynosi: %d\n", getpid());
	printf("Wartosc przekazana przez fork(): %d\n", PID);



	

		


	
	
}


