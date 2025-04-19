#include <stdio.h>
#include <math.h>

int main(){
    double area, tot_litro;
    double preco1, preco2, preco3, resto;
    int quant_lata3_1,quant_lata3_2, quant_lata1, quant_lata2;

    printf("Area: ");
    scanf("%lf", &area);

    tot_litro = (area/6.0)*1.1; // calculando total de litros necessarios
    quant_lata1 = (int) ceil(tot_litro/18.0); //quant de litros arredondada
    quant_lata2 = (int) ceil(tot_litro/3.6);

    preco1 = quant_lata1*80.0;
    preco2 = quant_lata2*25.0; 

    quant_lata3_1 = (int) tot_litro/18.0; 
    resto = tot_litro - (quant_lata3_1 *18.0); //o quanto falta usando uma lata de 18L inteira
    quant_lata3_2 = (int) ceil(resto/3.6);

    preco3 = (quant_lata3_1*80.0) + (quant_lata3_2*25.0);
    
    printf("Preco 1: %.2lf\nLatas: %d", preco1, quant_lata1);
    printf("\n\nPreco 2: %.2lf\nGaloes: %d", preco2, quant_lata2);
    printf("\n\nPreco 3: %.2lf\nLatas: %d\nGaloes: %d", preco3, quant_lata3_1,quant_lata3_2);
    return 0;
}