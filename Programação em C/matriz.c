#include <stdio.h>
#include <string.h>

int main(){
    int linha, coluna, mult;

    printf("Numero de linhas: ");
    scanf("%d", &linha); //determinando o n° de linhas
    printf("Numero de colunas: ");
    scanf("%d", &coluna); //determinando o n° de colunas

    mult = linha*coluna;

    int matriz[linha][coluna], n[mult];

    printf("Escreva os elementos da matriz: ");
    for(int i = 0; i < mult; i++){
        scanf("%d", &n[i]); 
    }

    for(int i=0; i< linha; i++){
        for(int j=0; j < coluna; j++){
            matriz[i][j] = n[i * coluna + j]; //Transforma o índice unidimensional em uma posição bidimensional na matriz.
        }
    }
    
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
- Para usar uma matriz em que o usuária vai decidir seu tamanho, é preciso fazer uma alocação dinâmica
- Contudo, nesse caso usei VMAs

*/