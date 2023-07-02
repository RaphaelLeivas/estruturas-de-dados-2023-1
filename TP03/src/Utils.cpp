#include "../include/Utils.hpp"

Utils::Utils() {}

Utils::~Utils() {}

void Utils::printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

void Utils::sortbyCountingSort(LinkedList* list, int maxFreq) {
    // ordena a lista em forma decrescente via countingsort
    int* count = new int[maxFreq + 1];
    int listSize = list->getSize();

    for (int i = 0; i < listSize; i++) {
        int num = list->getItem(i + 1).getFrequency();
        count[num]++;
    }

    // calcula a soma cumulativa em ordem decrescente
    for (int i = maxFreq - 1; i >= 0; i--) {
        count[i] += count[i + 1];
    }

    LinkedList sortedList;

    for (int i = 0; i < listSize; i++) {
        NodeItem currentItem = list->getItem(i + 1);
        sortedList.insertEnd(currentItem);
    }

    for (int i = listSize - 1; i >= 0; i--) {
        NodeItem arrI = list->getItem(i + 1);
        sortedList.setItem(arrI, count[arrI.getFrequency()]);
        count[arrI.getFrequency()]--;
    }

    for (int i = 0; i < list->getSize(); i++) {
        NodeItem currentItem = sortedList.getItem(i + 1);
        list->setItem(currentItem, i + 1);
    }

    delete[] count;
}

std::bitset<BYTE_IN_BITS> Utils::intTo8Bits(int number) {
    return std::bitset<8>(number);
};
