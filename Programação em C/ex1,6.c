#include <stdio.h>
#include <math.h>

int main(){
    float raio, area, rr;

    printf("Raio: ");
    scanf("%f", &raio);
    
    rr = pow(raio, 2);
    area = 3.14*rr;

    printf("Area = %0.1f", area);
    return 0;
}