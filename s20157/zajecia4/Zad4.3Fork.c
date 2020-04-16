#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char **argv){

	int i, j;
	pid_t PID;

printf("Proces programu: %d\n", getpid());



for (i = 0; i< 50; i++){	
switch(PID = fork()){
	
	case -1: 
	printf("Error in fork\n");
	
	case 0:
	switch(PID = fork()){
		case 0:
		printf("\t\t#%d Jestem potomkiem potomka, moj PID wynosi: %d\n",i, getpid());
		exit(0);
		wait(0);
	}
	wait(0);
	
	printf("#%d Jestem potomkiem, moj PID wynosi: %d\n",i, getpid());
	exit(0);
}
}
	for(j=0;j<100;j++){
		wait(0);
	}
	
	printf("\t\t!!!!!!!!!!!!Jestem RODZICEM, moj PID wynosi: %d\n", getpid());
	printf("Wartosc przekazana przez fork(): %d\n", PID);


	
	return 0;
}


