#include <stdio.h>

int main(){
    double tot_litro, area,preco;
    int latas;
    printf("Area em metros quadrados: ");
    scanf("%lf", &area); //formato para double
    
    tot_litro = area*0.33;
    latas = ceil(tot_litro/18.0); //arredonda pra cima
    preco = latas*80.0;

    printf("Latas: %d\nPreco Total: %.1f", latas, preco);
    return 0;
}