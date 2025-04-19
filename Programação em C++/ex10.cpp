#include <iostream>

using namespace std;

int main(){
    int vmax, vmot,multa;

    cout << "Velocidade maxima da avenida: ";
    cin >> vmax;

    cout << "Velocidade do motorista: ";
    cin >> vmot;

    multa = (vmot - vmax)*5;

    if(vmot <= vmax){
        cout << "Sem multa";
    }else{
        cout << "Multa: R$" << multa;
    }
    return 0;
}