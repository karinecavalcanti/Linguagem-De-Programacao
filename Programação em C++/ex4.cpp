#include <iostream>

using namespace std;

int main(){
    int a;
    cout << "Digite um numero: ";
    cin >> a;

    if(a % 2 == 0){
        cout << "O numero e par";
    }else{
        cout<< "O numero e impar";
    }
    return 0;
}