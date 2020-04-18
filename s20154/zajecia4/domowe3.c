#include <stdio.h>
#include <stdlib.h>

int fibo(int x){
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fibo(x-1)+fibo(x-2));
   }
}

int main(int argc, char **argv){
	printf("%d\n", fibo(atoi(argv[1])) );
}

