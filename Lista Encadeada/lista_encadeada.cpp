#include <iostream>
using namespace std;

struct Node {
    int dado;
    Node* proximo;
    Node(int val) : dado(val), proximo(nullptr) {}
};

class ListaEncadeada {
private:
    Node* cabeca;

public:
    ListaEncadeada() : cabeca(nullptr) {}

    void adicionar(int dado) {
        Node* novoNode = new Node(dado);
        if (!cabeca) {
            cabeca = novoNode;
        } else {
            Node* atual = cabeca;
            while (atual->proximo) {
                atual = atual->proximo;
            }
            atual->proximo = novoNode;
        }
    }

    void imprimir() {
        Node* atual = cabeca;
        while (atual) {
            cout << atual->dado << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    void bubbleSort() {
        bool trocado;
        Node* fim = nullptr;
        do {
            trocado = false;
            Node* atual = cabeca;
            while (atual->proximo != fim) {
                if (atual->dado > atual->proximo->dado) {
                    swap(atual->dado, atual->proximo->dado);
                    trocado = true;
                }
                atual = atual->proximo;
            }
            fim = atual;
        } while (trocado);
    }

    void insertionSort() {
        Node* ordenado = nullptr;
        Node* atual = cabeca;
        while (atual) {
            Node* proximo = atual->proximo;
            ordenado = inserirOrdenado(ordenado, atual);
            atual = proximo;
        }
        cabeca = ordenado;
    }

    Node* inserirOrdenado(Node* cabeca, Node* novoNode) {
        if (!cabeca || novoNode->dado < cabeca->dado) {
            novoNode->proximo = cabeca;
            return novoNode;
        } else {
            Node* atual = cabeca;
            while (atual->proximo && atual->proximo->dado < novoNode->dado) {
                atual = atual->proximo;
            }
            novoNode->proximo = atual->proximo;
            atual->proximo = novoNode;
            return cabeca;
        }
    }

    void mergeSort() {
        cabeca = mergeSortRecursivo(cabeca);
    }

    Node* mergeSortRecursivo(Node* cabeca) {
        if (!cabeca || !cabeca->proximo)
            return cabeca;

        Node* meio = obterMeio(cabeca);
        Node* proximoAoMeio = meio->proximo;
        meio->proximo = nullptr;

        Node* esquerda = mergeSortRecursivo(cabeca);
        Node* direita = mergeSortRecursivo(proximoAoMeio);

        return mesclarOrdenado(esquerda, direita);
    }

    Node* obterMeio(Node* cabeca) {
        Node* lento = cabeca;
        Node* rapido = cabeca->proximo;
        while (rapido && rapido->proximo) {
            lento = lento->proximo;
            rapido = rapido->proximo->proximo;
        }
        return lento;
    }

    Node* mesclarOrdenado(Node* esquerda, Node* direita) {
        if (!esquerda) return direita;
        if (!direita) return esquerda;

        if (esquerda->dado <= direita->dado) {
            esquerda->proximo = mesclarOrdenado(esquerda->proximo, direita);
            return esquerda;
        } else {
            direita->proximo = mesclarOrdenado(esquerda, direita->proximo);
            return direita;
        }
    }

    void quickSort() {
        cabeca = quickSortRecursivo(cabeca, obterFim(cabeca));
    }

    Node* quickSortRecursivo(Node* cabeca, Node* fim) {
        if (!cabeca || cabeca == fim)
            return cabeca;

        Node* novaCabeca = nullptr, *novoFim = nullptr;
        Node* pivo = particionar(cabeca, fim, &novaCabeca, &novoFim);

        if (novaCabeca != pivo) {
            Node* temp = novaCabeca;
            while (temp->proximo != pivo)
                temp = temp->proximo;
            temp->proximo = nullptr;

            novaCabeca = quickSortRecursivo(novaCabeca, temp);

            temp = obterFim(novaCabeca);
            temp->proximo = pivo;
        }

        pivo->proximo = quickSortRecursivo(pivo->proximo, novoFim);

        return novaCabeca;
    }

    Node* particionar(Node* cabeca, Node* fim, Node** novaCabeca, Node** novoFim) {
        Node* pivo = fim;
        Node* atual = cabeca, *anterior = nullptr, *cauda = pivo;

        while (atual != pivo) {
            if (atual->dado < pivo->dado) {
                if (!*novaCabeca)
                    *novaCabeca = atual;
                anterior = atual;
                atual = atual->proximo;
            } else {
                if (anterior)
                    anterior->proximo = atual->proximo;

                Node* temp = atual->proximo;
                atual->proximo = nullptr;
                cauda->proximo = atual;
                cauda = atual;
                atual = temp;
            }
        }

        if (!*novaCabeca)
            *novaCabeca = pivo;

        *novoFim = cauda;

        return pivo;
    }

    Node* obterFim(Node* cabeca) {
        while (cabeca && cabeca->proximo)
            cabeca = cabeca->proximo;
        return cabeca;
    }
};

int main() {
    ListaEncadeada lista;
    lista.adicionar(4);
    lista.adicionar(3);
    lista.adicionar(1);
    lista.adicionar(5);

    cout << "Lista Original: ";
    lista.imprimir();

    lista.bubbleSort();
    cout << "Bubble Sort: ";
    lista.imprimir();

    lista.insertionSort();
    cout << "Insertion Sort: ";
    lista.imprimir();

    lista.mergeSort();
    cout << "Merge Sort: ";
    lista.imprimir();

    lista.quickSort();
    cout << "Quick Sort: ";
    lista.imprimir();

    return 0;
}
