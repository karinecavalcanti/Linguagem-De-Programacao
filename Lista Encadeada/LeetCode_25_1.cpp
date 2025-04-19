#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insereInicio(Node** head, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = *head;
    *head = node;
}

void printLista(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

void bubbleSort(Node* head) {
    int troca;
    Node* ptr1;
    Node* lptr = nullptr; 

    do {
        troca = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                troca = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (troca);
}

int main() {
    Node* head = nullptr;
    int n, valor;

    std::cout << "Quantos termos? ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Digite os numeros : ";
        std::cin >> valor;
        insereInicio(&head, valor);
    }

    bubbleSort(head);

    std::cout << "\nLista ordenada: ";
    printLista(head);

    return 0;
}
