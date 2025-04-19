#include <stdio.h>

int main(){
    float s, total;
    int h;

    printf("Salario por hora: ");
    scanf("%f", &s);
    printf("Numero de horas trabalhadas por mes: ");
    scanf("%d", &h);

    total = s*h;

    printf("Total: %0.2f", total);

    return 0;
}
