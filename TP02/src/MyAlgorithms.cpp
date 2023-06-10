#include "../include/MyAlgorithms.hpp"

MyAlgorithms::MyAlgorithms() = default;
MyAlgorithms::~MyAlgorithms() = default;

// estavel
// pior caso: vetor entrada decrescente. é O(n^2)
// ele é simples, estável mas tem alto custo devido a n^2 de complexidade
// assintotica. codigo copiado dos slides do moodle
void MyAlgorithms::insertionSort(int* arr, int n) {
    int i, aux, j;

    for (i = 1; i < n; i++) {
        aux = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = aux;
    }
};

// estavel
// complexidade O(n log n), melhor que o insertion sort
// gasta mais espaco (usa recursividade)
// codigo copiado de https://www.geeksforgeeks.org/merge-sort/ e dos slides da
// disciplina
void MyAlgorithms::mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        this->mergeSort(arr, l, m);
        this->mergeSort(arr, m + 1, r);

        this->merge(arr, l, m, r);
    }
};

void MyAlgorithms::printArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void MyAlgorithms::fillArrayWithRandom(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
}

// funcoes auxiliares
void MyAlgorithms::merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
