#include <iostream>
#include <vector>
using namespace std;

class Aluno{
protected: //dá acesso a classe derivada
    string Nome, Dre;
    int Quant_materias;
    vector<string> Materias; // Para armazenar os nomes das matérias
    vector<int> Notas, Pesos; // Para armazenar notas e pesos
    float CR, media;
    int soma_pesos;

public:   
    void Introducao(){ //função "vazia" para introduzir-se
        cout << "Nome: ";
        cin >> Nome;
        cout << "DRE: ";
        cin >> Dre;
        cout << "Quantidade de Materias: ";
        cin >> Quant_materias;

        // Redimensionar os vetores de acordo com a quantidade de matérias (ponteiro)
        Materias.resize(Quant_materias); //array dinâmica
        Notas.resize(Quant_materias); 
        Pesos.resize(Quant_materias);

        for(int i = 0; i < Quant_materias; i++){
            cout << "Nome da materia " << i+1 << ": ";
            cin >> Materias[i];
        }
        for(int i = 0; i < Quant_materias; i++){
            cout << "\nNota " << Materias[i] << ": ";
            cin >> Notas[i];
            cout << "Peso " << Materias[i] << ": ";
            cin >> Pesos[i];
        }
    }
    float CalculaCR() {
        soma_pesos = 0;
        media = 0;
        for(int i = 0; i < Quant_materias; i++){
            soma_pesos += Pesos[i];
            media += Notas[i] * Pesos[i];
        }
        CR = media/soma_pesos;
        return CR;
    }
};
class Aluno_G : public Aluno{ 
private:
    string Cursando;

public:

    Aluno_G(string nome, string dre, int quant_materias, const vector<string>& materias, const vector<int>& notas,
    const vector<int>& pesos, float cr, string cursando) {
    Nome = nome;
    Dre = dre;
    Quant_materias = quant_materias;
    Materias = materias;
    Notas = notas;
    Pesos = pesos;
    CR = cr;
    Cursando = cursando;
    
    }

    void MostraIntroducao() const{
        cout << "Nome: " << Nome << "\nDRE: "<< Dre;
        cout<< "\nMatérias: ";
        for(int i = 0; i< Quant_materias; i++){
            cout<< Materias[i] << " ";
        }
        cout << "Cursando:" << Cursando;
        cout << "CR: " << CR;
    }

};
class Aluno_P : public Aluno{
private:
    string Graduacao;
    string Pos;
    
public: 
    Aluno_P(string nome, string dre, int quant_materias, const vector<string>& materias, const vector<int>& notas,
    const vector<int>& pesos, float cr, string graduacao, string pos){
    Nome = nome;
    Dre = dre;
    Quant_materias = quant_materias;
    Materias = materias;
    Notas = notas;
    Pesos = pesos;
    CR = cr;
    Graduacao = graduacao;
    Pos = pos;

    }
    void MostraIntroducao() const{
        cout << "Nome: " << Nome << "\nDRE: "<< Dre;
        cout<< "\nMatérias: ";
        for(int i = 0; i< Quant_materias; i++){
            cout<< Materias[i] << " ";
        }
        cout << "Graduacao:" << Graduacao;
        cout << "Pos: " << Pos;
        cout << "CR: " << CR;
    }

};


int main(){ //área principal
    Aluno_G aluno_g; //colocando os dados dos funcionários da classe funcionário através da função
    alunog.Introducao();

    int indice;
    do{
        cout << "Digite 1 para identificar-se como aluno da graduacao ou 2 para identificar-se como aluno da pos-graducao";
        cin >> indice;

        switch(indice){
            case 1:
                
        }

    }
    return 0;
}