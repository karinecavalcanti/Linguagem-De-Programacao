#include <stdio.h>

int main(){
    float m, cm;
    printf("Digite uma medida em metros: ");
    scanf("%f", &m);

    cm = m*100;

    printf("A medida em centimetros e: %0.1f", cm);
    return 0;
}