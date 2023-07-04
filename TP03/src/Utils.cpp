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

std::bitset<BYTE_IN_BITS> Utils::charTo8Bits(char c) {
    int number = (int)c;
    return std::bitset<8>(number);
};

void Utils::printBytes(std::string bits) {
    for (int i = 0; i < bits.size(); ++i) {
        if (i % 8 == 0 && i != 0) {
            std::cout << " ";
        } else {
            std::cout << bits[i];
        }
    }

    std::cout << std::endl;
}

void Utils::writeBytesToFile(std::ofstream& file, std::string buffer) {
    while (buffer.size() >= 8) {
        unsigned char byte = 0;
        for (int i = 0; i < 8; i++) {
            if (buffer[i] == '1') {
                byte |= (1 << (7 - i));
            }
        }

        file.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
        buffer = buffer.substr(8);
    }

    if (!buffer.size()) {
        // ja terminou
        return;
    }

    //add trailing zeros no que sobrou ate formar 8 bits 
    while (buffer.size() % 8 != 0) {
        buffer += "0";
    }

    // ai escreve
    unsigned char byte = 0;
    for (int i = 0; i < 8; i++) {
        if (buffer[i] == '1') {
            byte |= (1 << (7 - i));
        }
    }

    file.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
}
