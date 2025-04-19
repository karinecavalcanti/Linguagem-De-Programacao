#include <stdio.h>

int main(){
    int vetor[5], a;

    printf("Digite 5 numeros: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i<5; i++){
        for(int j = i; j < 5; j++){
            if(vetor[i] > vetor[j]){
                a = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = a;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        printf("%d", vetor[i]);
    }

    return 0;
}