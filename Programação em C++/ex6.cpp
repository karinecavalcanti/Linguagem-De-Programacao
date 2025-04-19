#include <iostream>

using namespace std;

int main(){
    int vetor[3];
    float maior, menor, inter;

    for(int i = 0; i < 3; i++){
        cout << "Digite um numero: ";
        cin >> vetor[i];
    }
    maior = vetor[0];
    menor = vetor[0];
    
    for(int i = 0; i < 3; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }else if(vetor[i] < menor){
            menor = vetor[i];
        }else{
            inter = vetor[i];
        }
    }
    cout << maior << "\n" << menor << "\n" << inter;

    return 0;
}