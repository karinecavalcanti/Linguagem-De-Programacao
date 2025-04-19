#include <stdio.h>

int main(){
    int a;

    printf("Digite um numero: ");
    scanf("%d", &a);

    if(a < 0){
        printf(" o numero e negativo");
    }else{
        printf("o numero e positivo");
    }

    return 0;
}