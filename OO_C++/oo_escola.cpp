#include <iostream>

using namespace std;

class Funcionario {
private:
    string Nome, Empresa, Cpf, Sexo;
    int Idade;

public:   
    void Introducao(){ //função "vazia" para introduzir-se
        cout << "Nome: ";
        cin >> Nome;
        cout << "Empresa: ";
        cin >> Empresa;
        cout << "Cpf: ";
        cin >> Cpf;
        cout << "Sexo: ";
        cin >> Sexo;
        cout << "Idade: ";
        cin >> Idade;
    }
    void ListaFuncionario() {
        cout << "\n\n" << Nome << "\n" << Empresa << "\n" << Cpf << "\n" << Sexo << "\n" << Idade;
    }
    void DemitirFuncionario(){
        
    }
};

int main(){ //área principal
    Funcionario func1 = Funcionario(); //colocando os dados dos funcionários da classe funcionário através da função
    func1.Introducao();
    func1.ListaFuncionario();
    return 0;
}