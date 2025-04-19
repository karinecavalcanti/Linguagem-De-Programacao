#include <stdio.h>

int main(){
    char sexo;
    printf("Digite um sexo: ");
    scanf("%c", &sexo);

    if(sexo == 'F'){
        printf("Feminino");
    }
    else if(sexo == 'M'){
        printf("Masculino");
    }
    else{
        printf("sexo não reconhecido");
    }
    return 0;
}