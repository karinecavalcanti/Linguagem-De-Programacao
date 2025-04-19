#include <stdio.h>

int main(){
    int a, b;

    printf("numero 1: ");
    scanf("%d", &a);

    printf("numero 2: ");
    scanf("%d", &b);

    if(a < b){
        printf("%d",b);
    }
    else if(a > b){
        printf("%d", a);
    }
    else{
        printf("os numeros sao iguais");
    }

    return 0;
}