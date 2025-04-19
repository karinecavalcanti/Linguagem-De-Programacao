#include <stdio.h>
#include <string.h>
#include <ctype.h>

// quantidade de caracteres, palavras, simbolos e numeros numa frase

int main(){
    int caracter = 0 , letras = 0, simbolo = 0, numero = 0, palavra = 0;
    char frase[100];
    scanf("%[^\n]", frase);

    caracter = strlen(frase);

    for(int i=0; i < caracter; i++){
        if (isalpha(frase[i])){
            letras += 1;
        }
        else if (isdigit(frase[i])){
            numero += 1;
        }
        else{
            simbolo += 1;
        }
    }
    palavra = simbolo + 1;


    printf("%d",caracter);
    printf("\n%d", letras);
    printf("\n%d",simbolo);
    printf("\n%d",numero); 
    printf("\n%d", palavra);

    return 0;
}