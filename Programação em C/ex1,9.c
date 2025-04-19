#include <stdio.h>

int main(){
    int c, f;
    printf("Digite uma temperatura em Fahrenheit: ");
    scanf("%d", &f);

    c = 5*((f-32)/9);

    printf("%d", c);
    return 0;
}