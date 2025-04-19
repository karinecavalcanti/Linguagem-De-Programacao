#include <stdio.h>
#include <string.h>
int main(){
    int n[4], soma = 0; 
    float media;
    for(int i = 0; i<4; i++){
        printf("Digite a %d nota: ", i+1);
        scanf("%d", &n[i]);
    }
    for(int i = 0; i<4; i++){
        soma += n[i];
    }
    media = soma/4.0;
    printf("Sua media e: %0.1f", media);


    return 0;
}