#include <iostream>
#include <vector>
using namespace std;

class Resultado {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);  // Para armazenar o número de elementos menores à direita
        vector<int> indices(n, 0);  // Para armazenar os índices dos elementos
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        // Chama o merge sort
        mergeSort(nums, indices, count, 0, n - 1);
        return count;
    }
    
private:
    void mergeSort(vector<int>& nums, vector<int>& indices, vector<int>& count, int esq, int dir) {
        if (esq >= dir) return;
        
        int meio = esq + (dir - esq) / 2;
        mergeSort(nums, indices, count, esq, meio);
        mergeSort(nums, indices, count, meio + 1, dir);
        merge(nums, indices, count, esq, meio, dir);
    }
    void merge(vector<int>& nums, vector<int>& indices, vector<int>& count, int esq, int meio, int dir) {
        vector<int> temp(dir - esq + 1);
        int i = esq, j = meio + 1, k = 0;
        int dirCount = 0;  // count quantos elementos do lado direito são menores
        
        while (i <= meio && j <= dir) {
            if (nums[indices[j]] < nums[indices[i]]) {
                // Se o elemento do lado direito é menor, aumenta a countgem de menores à direita
                dirCount++;
                temp[k++] = indices[j++];
            } else {
                // Adiciona a countgem de elementos menores à direita para indices[i]
                count[indices[i]] += dirCount;
                temp[k++] = indices[i++];
            }
        }
        // Processa quaisquer elementos restantes no lado esquerdo
        while (i <= meio) {
            count[indices[i]] += dirCount;
            temp[k++] = indices[i++];
        }
        // Processa quaisquer elementos restantes no lado direito
        while (j <= dir) {
            temp[k++] = indices[j++];
        }
        // Copia de volta para o array de índices
        for (int i = esq; i <= dir; ++i) {
            indices[i] = temp[i - esq];
        }
    }
};

int main() {
    Resultado resultado;
    vector<int> nums;
    int n;

    cout << "Digite a quantidade de números: ";
    cin >> n;

    cout << "Digite os números: ";
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    // Calcula o resultado
    vector<int> result = resultado.countSmaller(nums);
    
    cout << "Resultado: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}
