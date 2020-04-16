#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char **argv){
	
	pid_t PID;

printf("Proces programu: %d\n", getpid());

switch(PID = fork()){
	
	case -1: 
	printf("Error in fork\n");
	
	case 0:
	printf("Jestem potomkiem, moj PID wynosi: %d\n", getpid());
	printf("Wartosc przekazana przez fork(): %d\n", PID);
	return 0;
	
	default:
	
	printf("Jestem rodzicem, moj PID wynosi: %d\n", getpid());
	printf("Wartosc przekazana przez fork(): %d\n", PID);

	wait(0);
	return 0;
}

}
