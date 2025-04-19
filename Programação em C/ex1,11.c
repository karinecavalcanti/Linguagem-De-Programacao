#include <stdio.h>
#include <math.h>

int main(){
    int x,y,a,b;
    float z, c;
    printf("Digite um numero: ");
    scanf("%d", &x);
    printf("Digite outro numero: ");
    scanf("%d", &y);
    printf("Digite outro numero: ");
    scanf("%f", &z);

    a = (x*2)*(y/2);
    b = (3*x) + z;
    c = pow(z,3);

    printf("%d,%d,%.1f", a,b,c);
    
    return 0;
}