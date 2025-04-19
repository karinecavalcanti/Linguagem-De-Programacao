#include <stdio.h>

int main(){
    float altura, peso;
    printf("Altura: ");
    scanf("%f", &altura);

    peso = (72.7*altura)-58;

    printf("Peso ideal: %0.1f", peso);

    return 0;
}