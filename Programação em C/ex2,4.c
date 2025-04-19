#include <stdio.h>
#include <string.h>

int main(){
    // char vogal[6] = "aeiou";
    char letra;
    printf("Digite uma letra: ");
    scanf("%c", &letra);

    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        printf("vogal");
    }else{
        printf("consoante");
    }

    return 0;
}