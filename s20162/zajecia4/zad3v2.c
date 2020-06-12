#include <stdlib.h>
#include <stdio.h>

int maksimum(int a, int b);
int minimum(int a, int b);
int suma(int a, int b);
int forAll(int *tab, int n, int (*funkcja)(int, int));

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
    v=forAll(tab, i , wybranaFunkcja[z]);
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
int forAll(int *tab, int n, int (*funkcja)(int, int)){
    int v = tab[0];
    int i;
    for(i=1; i<n; i++){
        v=funkcja(v,tab[i]);
    }
    return v;
}