#include <stdio.h>

int main(){
    float peso, excesso, multa;

    printf("Peso: ");
    scanf("%f", &peso);

    if(peso>50){
        excesso = peso - 50;
    }
    multa = excesso * 4.00;
    printf("Peso:  %.1f\nExcesso: %.1f\nMulta: %.1f ", peso, excesso, multa);

    return 0;
}