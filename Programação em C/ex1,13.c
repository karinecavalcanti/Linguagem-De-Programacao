#include <stdio.h>

int main(){
    float altura, peso;
    char sexo;
    printf("Altura: ");
    scanf("%f", &altura);
    printf("Sexo: ");
    scanf(" %c", &sexo);

    if(sexo == 'h'){
        peso = (72.7*altura)-58;
        printf("Peso ideal: %.1f", peso);
    }
    else if(sexo == 'm'){
        peso = (62.1*altura)-44.7;
        printf("Peso ideal: %.1f", peso);
    }

    return 0;
}