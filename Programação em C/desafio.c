#include <stdio.h>
#include <string.h>
#define MAX_PRODUTOS 100

typedef struct{
    int i, indice,a;
    int cod, quant;
    float preco;
    char nome[50];
} Produto;

int insereProduto(Produto produtos[], int numProdutos){ //inserir

    if (numProdutos >= MAX_PRODUTOS) { //
        printf("Número máximo de produtos atingido.\n");
        return numProdutos;
    }

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &produtos[numProdutos].cod);
    
    
    for(int i =0; i < numProdutos; i++){
        if(produtos[numProdutos].cod == produtos[i].cod){ //verifica se o codigo ja existe
            printf("\nCodigo ja existente\n");
            return numProdutos;
        }
    }
    printf("Digite o nome do produto: ");
    scanf("%s", produtos[numProdutos].nome);

    for(int i =0; i < numProdutos; i++){
        if(strcmp(produtos[i].nome, produtos[numProdutos].nome) == 0){
            printf("\nProduto ja cadastrado\n");
            return numProdutos;
        }
    }

    printf("Digite o preco do produto: ");
    scanf("%f", &produtos[numProdutos].preco);
    printf("Digite o quantidade em estoque: ");
    scanf("%d", &produtos[numProdutos].quant);
    
    numProdutos++;
    return numProdutos;
}
void listaProdutos(Produto produto[], int numProdutos){//lista todos os produtos
    for(int i = 0; i < numProdutos; i++){
        printf("\nCodigo: %d", produto[i].cod);
        printf("\nNome: %s", produto[i].nome);
        printf("\nPreco: R$%.2f", produto[i].preco);
        printf("\nQuantidade: %d\n\n", produto[i].quant);
    }
}

void buscaProdutos(Produto produto[], int numProdutos){
    char nomeN[50];
    int a;
    printf("\nDigite o nome do produto: ");
    scanf("%s", nomeN);
    
    a = 0;
    for(int i = 0; i < numProdutos; i++){
        if (strcmp(produto[i].nome, nomeN) == 0) { //procura se o nome já existe no array, se sim, continua a busca
            printf("\nCodigo: %d", produto[i].cod);
            printf("\nNome: %s", produto[i].nome);
            printf("\nPreco: R$%.2f", produto[i].preco);
            printf("\nQuantidade: %d\n", produto[i].quant);
            a = 1;
            break;
        }
    }
    if(!a){ //se não, para e monstra a mensagem abaixo
        printf("\nProduto inexistente\n");
    }
}

int excluirProdutos(Produto produto[], int numProdutos){
    char nomeE[50];
    printf("\nDigite o nome do produto a ser excluido: ");
    scanf("%s", nomeE);
    
    for (int i = 0; i < numProdutos; i++) { 
        if (strcmp(produto[i].nome, nomeE) == 0) {// procura se o nome já foi inserido anteriormente, se sim, continua
            for (int j = i; j < numProdutos - 1; j++) {// Desloca todos os produtos para "cima" no array para preencher o espaço vazio
                produto[j] = produto[j + 1];
            }
            numProdutos--;
            printf("Produto excluido com sucesso.\n");
            return numProdutos;
        }
    }// se não, mostra a mensagem abaixo
    printf("Produto nao encontrado.\n");
    return numProdutos;
}


int main(){
    Produto produtos[MAX_PRODUTOS];

    int indice;
    int numProdutos = 0; //iniciando o total de produtos com 0
    do { 
        printf("\n=== Menu de Opcoes ===\n1.Inserir produtos \n2.Listar todos os produtos \n3.Buscar produto por nome \n4.Excluir produto por nome \n5.Sair \nEscolha uma opcao: ");
        scanf("%d", &indice);

        switch (indice){
            case 1: //inserir
                numProdutos = insereProduto(produtos, numProdutos);
                break;
            case 2: // listar
                listaProdutos(produtos, numProdutos);
                break;
            case 3: //buscar
                buscaProdutos(produtos, numProdutos);
                break;
            case 4: //excluir
                numProdutos = excluirProdutos(produtos, numProdutos);
            case 5: //sair
                break;
            // case ' ': como fazer o programa rodar quando aperta somente enter
            //     break;

            default:
                printf("Opcao inexistente");
                break;
        }
    }while(indice != 5); //enquanto o usuario não escolhe a opção 5 (sair), ele continua rodando o programa

    return 0;

}