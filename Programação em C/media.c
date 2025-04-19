#include <stdio.h>
#include <string.h>
int main(){
    int a, soma = 0; 
    float media;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &a);

    int n[a];

    for(int i = 0; i<a; i++){
        printf("Digite a %d nota: ", i+1);
        scanf("%d", &n[i]);
    }
    for(int i = 0; i<a; i++){
        soma += n[i];
    }
    media = soma/a;
    printf("Sua media e: %0.1f", media);


    return 0;
}