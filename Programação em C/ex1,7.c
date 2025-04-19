#include <stdio.h>

int main(){
    float l, area, dobro;
    printf("Lado: ");
    scanf("%f", &l);
    area = l*l;
    dobro = 2*area;

    printf("Dobro da area: %0.1f", dobro);

    return 0;
}