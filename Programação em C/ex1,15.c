#include <stdio.h>

int main(){
    float salario, h;
    float sal_bruto, inss, sindicato, ir, sal_liquido;

    printf("Salario por hora: ");
    scanf("%f", &salario);
    printf("Numero de horas trabalhadas: ");
    scanf("%f",&h);

    sal_bruto = salario*h;
    inss = sal_bruto*0.08;
    sindicato = sal_bruto*0.05;
    ir = sal_bruto*0.11;
    sal_liquido = sal_bruto-ir-inss-sindicato;

    printf("+ Salario Bruto: R$ %.1f\n- IR (11): R$%.1f\n- INSS (8): R$%.1f\n- Sindicato (5): R$%.1f\n= Salario Liquido: R$%.1f", sal_bruto, ir, inss, sindicato, sal_liquido);
    return 0;
}