#include <stdio.h>

int main(){
    int lista[3], maior;

    for(int i = 0; i < 3; i++){
        printf("Digite um numero: ");
        scanf("%d", &lista[i]);
    }

    maior = lista[1];

    for(int i = 0; i < 3; i++){
        if(lista[i] > maior){
            maior = lista[i];
        }
    }
    printf("%d", maior);
    return 0;
}