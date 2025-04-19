#include <stdio.h>

int main(){
    int lista[3], menor;

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
    printf("%d", menor);
    return 0;
}