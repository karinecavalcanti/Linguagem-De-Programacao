#include <stdio.h>

int main(){
    int lista[3], menor, maior;

    for(int i = 0; i < 3; i++){
        printf("Digite um numero: ");
        scanf("%d", &lista[i]);
    }

    menor = lista[1];

    for(int i = 0; i < 3; i++){
        if(lista[i] < menor){
            menor = lista[i];
        }
    }
    maior = lista[1];

    for(int i = 0; i < 3; i++){
        if(lista[i] > maior){
            maior = lista[i];
        }
    }

    printf("Maior numero: %d \nMenor numero: %d", maior, menor);

    return 0;
}