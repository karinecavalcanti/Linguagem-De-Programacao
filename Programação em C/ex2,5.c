#include <stdio.h>

int main(){
    float n1, n2, media;

    printf("Nota 1: ");
    scanf("%f", &n1);
    printf("Nota 2: ");
    scanf("%f", &n2);

    media = (n1+n2)/2;

    if(media >= 7 &&  media < 10){
        printf("Aprovado");
    }
    else if(media == 10){
        printf("Aprovado com distincao");
    }
    else{
        printf("Reprovado");
    }


    return 0;
}