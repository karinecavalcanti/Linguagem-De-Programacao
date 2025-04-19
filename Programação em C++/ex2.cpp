#include <iostream>

using namespace std;

int main(){
    int vetor[3],soma = 0;
    float media;
    for(int i = 0; i < 3; i++){
        cout << "Digite um numero: ";
        cin >> vetor[i];
        soma += vetor[i];
    }
    media = soma/3;
    cout << "Media: " << media;
    return 0;
}