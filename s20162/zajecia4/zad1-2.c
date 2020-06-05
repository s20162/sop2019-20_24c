#include <stdio.h>

int main() {
    int howmany=0; 
    int sum=0;
    int digit=0;
    printf("podaj ile będziesz sumował liczb\n");
    scanf("%d", &howmany);
    printf("podaj %d liczb do zsumowania\n", howmany);
    while (howmany>0)
    {
        scanf("%d", &digit);
        sum += digit;
        howmany--;
    }
    printf("wynik sumowania to: %d\n", sum);

    return sum;
}