#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "../include/customTime.h"

#define debug(a) std::cout << a << std::endl

void shellSort(int* vet, int size) {
    int i, j, value;
    int h = 40;  // valor inicial de h
    while (h > 0) {
        for (i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h - 1 && value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h - 2;
        if (h == 0) h = 1;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;

    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main(int argc, char** argv) {
    int arr[] = {60, 20, 40, 70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    printArray(arr, n);

    int64_t before = getUnixTimestamp(NANOSECONDS_OPTION);
    heapSort(arr, n);
    int64_t after = getUnixTimestamp(NANOSECONDS_OPTION);
    printf("Diff = %" PRId64 "", after - before);
    printf("\n");

    std::cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}