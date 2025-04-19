#include <iostream>
using namespace std;

struct Node {
    int dado;
    Node* next;
    Node(int val) : dado(val), next(nullptr) {}
};

class ListaEncadeada {
private:
    Node* head;

public:
    ListaEncadeada() : head(nullptr) {}

    // Função para adicionar um novo nó ao final da lista
    void adicionar(int dado) {
        Node* novoNode = new Node(dado);
        if (!head) {
            head = novoNode;
        } else {
            Node* atual = head;
            while (atual->next) {
                atual = atual->next;
            }
            atual->next = novoNode;
        }
    }

    // Função para exibir os elementos da lista
    void exibir() {
        Node* atual = head;
        while (atual) {
            cout << atual->dado << " ";
            atual = atual->next;
        }
        cout << endl;
    }

    // Função para resetar a lista com novos valores (usado para cada exemplo)
    void resetar() {
        limpar();
        int valores[] = {8, 3, 5, 1, 9, 4, 2, 7};
        for (int valor : valores) {
            adicionar(valor);
        }
    }

    // Função para liberar memória de toda a lista
    void limpar() {
        Node* atual = head;
        while (atual) {
            Node* next = atual->next;
            delete atual;
            atual = next;
        }
        head = nullptr;
    }

    // Implementação do Bubble Sort
    void bubbleSort() {
        if (!head) return;
        Node* fim = nullptr;
        bool trocado;
        do {
            trocado = false;
            Node* atual = head;
            while (atual->next != fim) {
                if (atual->dado > atual->next->dado) {
                    swap(atual->dado, atual->next->dado);
                    trocado = true;
                }
                atual = atual->next;
            }
            fim = atual;
        } while (trocado);
    }

    // Implementação do Insertion Sort
    void insertionSort() {
        if (!head) return;
        Node* ordenado = nullptr;
        Node* atual = head;
        while (atual) {
            Node* next = atual->next;
            ordenado = inserirOrdenado(ordenado, atual);
            atual = next;
        }
        head = ordenado;
    }

    Node* inserirOrdenado(Node* ordenado, Node* novoNode) {
        if (!ordenado || novoNode->dado < ordenado->dado) {
            novoNode->next = ordenado;
            return novoNode;
        }
        Node* atual = ordenado;
        while (atual->next && atual->next->dado < novoNode->dado) {
            atual = atual->next;
        }
        novoNode->next = atual->next;
        atual->next = novoNode;
        return ordenado;
    }

    // Implementação do Merge Sort
    void mergeSort() {
        head = mergeSortRecursivo(head);
    }

    Node* mergeSortRecursivo(Node* node) {
        if (!node || !node->next) return node;

        Node* meio = obterMeio(node);
        Node* nextDoMeio = meio->next;
        meio->next = nullptr;

        Node* esq = mergeSortRecursivo(node);
        Node* dir = mergeSortRecursivo(nextDoMeio);

        return mesclarOrdenado(esq, dir);
    }

    Node* obterMeio(Node* node) {
        if (!node) return node;
        Node* lento = node;
        Node* rapido = node->next;
        while (rapido && rapido->next) {
            lento = lento->next;
            rapido = rapido->next->next;
        }
        return lento;
    }

    Node* mesclarOrdenado(Node* esq, Node* dir) {
        if (!esq) return dir;
        if (!dir) return esq;

        if (esq->dado <= dir->dado) {
            esq->next = mesclarOrdenado(esq->next, dir);
            return esq;
        } else {
            dir->next = mesclarOrdenado(esq, dir->next);
            return dir;
        }
    }

    // Implementação do Quick Sort
    void quickSort() {
        head = quickSortRecursivo(head, obterFim(head));
    }

    Node* quickSortRecursivo(Node* head, Node* fim) {
        if (!head || head == fim) return head;

        Node* novahead = nullptr, *novoFim = nullptr;
        Node* pivo = particionar(head, fim, &novahead, &novoFim);

        if (novahead != pivo) {
            Node* temp = novahead;
            while (temp->next != pivo) temp = temp->next;
            temp->next = nullptr;

            novahead = quickSortRecursivo(novahead, temp);

            temp = obterFim(novahead);
            temp->next = pivo;
        }

        pivo->next = quickSortRecursivo(pivo->next, novoFim);

        return novahead;
    }

    Node* particionar(Node* head, Node* fim, Node** novahead, Node** novoFim) {
        Node* pivo = fim;
        Node* atual = head;
        Node* anterior = nullptr;
        Node* cauda = pivo;

        while (atual != pivo) {
            if (atual->dado < pivo->dado) {
                if (!*novahead) *novahead = atual;
                anterior = atual;
                atual = atual->next;
            } else {
                if (anterior) anterior->next = atual->next;

                Node* temp = atual->next;
                atual->next = nullptr;
                cauda->next = atual;
                cauda = atual;
                atual = temp;
            }
        }

        if (!*novahead) *novahead = pivo;
        *novoFim = cauda;

        return pivo;
    }

    Node* obterFim(Node* node) {
        while (node && node->next) node = node->next;
        return node;
    }
};

int main() {
    ListaEncadeada lista;

    lista.resetar();
    cout << "Lista Original: ";
    lista.exibir();

    lista.bubbleSort();
    cout << "Bubble Sort: ";
    lista.exibir();

    lista.resetar();
    lista.insertionSort();
    cout << "Insertion Sort: ";
    lista.exibir();

    lista.resetar();
    lista.mergeSort();
    cout << "Merge Sort: ";
    lista.exibir();

    lista.resetar();
    lista.quickSort();
    cout << "Quick Sort: ";
    lista.exibir();

    return 0;
}
