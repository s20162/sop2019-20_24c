#include <stdlib.h>
#include <stdio.h>

int maksimum(int a, int b);
int minimum(int a, int b);
int suma(int a, int b);


int main(int argc, char** argv) {
    int z;
    int n;
    int i=0;
    int v;
    int (*wybranaFunkcja[3])(int,int) = {&maksimum, &minimum, &suma};
    scanf("%d", &z);
    scanf("%d", &n);
    int tab[n];
    while (n>0) {
        scanf("%d", &tab[i]);        
        n--;
        i++;    
    }
    v = tab[0];
    for(i=1; i<sizeof(tab)/sizeof(int); i++){
        v=wybranaFunkcja[z](v,tab[i]);
    }
    printf("%d\n", v);
      

    return 0;
}

int maksimum(int a, int b){
    if(a>b) {
        return a;
    } else {
        return b;
    }
}
int minimum(int a, int b){
    if(a<b) {
        return a;
    } else {
        return b;
    }
}
int suma(int a, int b){
    return a+b;
}