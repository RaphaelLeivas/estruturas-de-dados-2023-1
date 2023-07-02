#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/LinkedList.hpp"
#include "../include/HuffmanTree.hpp"
#include "../include/Utils.hpp"

bool isCompression = true;

std::string fileToComp;
std::string fileToDecomp;

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "c:d:")) != EOF) {
        if (c == 'c') {
            fileToComp = optarg;
        }
        if (c == 'd') {
            fileToDecomp = optarg;
        }
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    Utils utils = Utils();
    LinkedList list = LinkedList();

    if (isCompression) {
        std::ifstream inputFile(fileToComp);
        char ch;

        int maxFreq = 0;  // usado na ordenação via counting sort

        while (inputFile.get(ch)) {
            // verifica se ja existe esse caracter
            Cell* foundCell = list.getCellByChar(ch);
            int newFreq;

            if (foundCell == nullptr) {
                // nao existe o caracter. cria um novo e salva
                NodeItem newItem = NodeItem();
                newItem.setData(ch);
                newFreq = 1;
                newItem.setFrequency(newFreq);

                list.insertEnd(newItem);
            } else {
                // caracter ja existe na lista.
                NodeItem currentItem = foundCell->getItem();
                newFreq = currentItem.getFrequency() + 1;
                currentItem.setFrequency(newFreq);

                foundCell->setItem(currentItem);
            }

            if (newFreq >= maxFreq) {
                maxFreq = newFreq;
            }
        }

        if (!list.getSize()) {
            std::cout
                << "ERRO: arquivo de entrada vazio. Não é possível comprimir"
                << std::endl;
            return 0;
        }

        // aux que salva a lista original
        LinkedList originalList = LinkedList();

        for (int i = 0; i < list.getSize(); i++) {
            NodeItem currentItem = list.getItem(i + 1);
            originalList.insertEnd(currentItem);
        }

        // ordena a lista com counting sort
        utils.sortbyCountingSort(&list, maxFreq);

        while (list.getSize() != 1) {
            Cell* left = list.removeEndCell();
            Cell* right = list.removeEndCell();

            Cell* newCell = new Cell();
            newCell->left = left;
            newCell->right = right;

            NodeItem newItem = NodeItem();
            int newFreq = left->getItem().getFrequency() +
                          right->getItem().getFrequency();
            newItem.setFrequency(newFreq);
            newCell->setItem(newItem);

            list.insertCellAtOrder(newCell);
        }

        // agora, a unica celula na lista encadeada é a raiz da arvore de
        // Huffman.
        HuffmanTree tree = HuffmanTree();
        Cell* root = list.getFirstCell();
        tree.setRoot(root);

        // adiciona um codigo a cada caracter da lista
        if (originalList.getSize() == 1) {
            // se so tem um caracter na entrada
            NodeItem item = root->getItem();
            item.setCode("1");
            root->setItem(item);
        } else {
            tree.assignHuffmanCodes(root, "");
        }

        // agora percorre o arquivo de entrada mais um vez. para cada caracter,
        // adicina o correspondente codigo no arquivo de saida
        std::ifstream inputFile2(fileToComp);
        std::ofstream outputFile(fileToDecomp, std::ios::binary);

        std::string buffer;

        while (inputFile2.get(ch)) {
            Cell* foundCell = tree.findCellByChar(root, ch);

            if (foundCell == nullptr) {
                throw std::runtime_error(
                    "Compression error: not found character " + ch);
            }

            // debug(foundCell->getItem().getCode());
            buffer += foundCell->getItem().getCode();

            // Write complete bytes to the output file
            while (buffer.size() >= 8) {
                unsigned char byte = 0;
                for (int i = 0; i < 8; i++) {
                    if (buffer[i] == '1') {
                        byte |= (1 << (7 - i));
                    }
                }

                outputFile.write(reinterpret_cast<const char*>(&byte),
                                 sizeof(byte));
                buffer = buffer.substr(8);
            }
        }

        // Write the remaining bits (if any) padded with zeros
        if (!buffer.empty()) {
            unsigned char byte = 0;
            for (long unsigned int i = 0; i < buffer.size(); i++) {
                if (buffer[i] == '1') {
                    byte |= (1 << (7 - i));
                }
            }

            // Pad the remaining bits with zeros
            int remainingBits = 8 - buffer.size();
            byte <<= remainingBits;

            outputFile.write(reinterpret_cast<const char*>(&byte),
                             sizeof(byte));
        }

        inputFile.close();
        inputFile2.close();
        outputFile.close();

        // tree.walk(WALK_TYPES::PRE_ORDER);
    } else {
        std::ifstream inputFile(fileToDecomp, std::ios::binary);

        while (!inputFile.eof()) {
            unsigned char byte;
            inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));

            int charAsInt = (int)byte;

            std::cout << utils.intTo8Bits(charAsInt) << " ";
        }

        std::cout << std::endl;
        inputFile.close();
    }

    return 0;
}