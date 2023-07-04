#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/HuffmanTree.hpp"
#include "../include/LinkedList.hpp"
#include "../include/Utils.hpp"

bool isCompression = false;

std::string fileToComp;
std::string fileToDecomp;

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "cd")) != EOF) {
        if (c == 'c') {
            isCompression = true;
        }
        if (c == 'd') {
            isCompression = false;
        }
    }

    // mais info:
    // https://www.tutorialspoint.com/getopt-function-in-c-to-parse-command-line-arguments
    for (; optind < argc; optind++) {  // when some extra arguments are passed
        if (optind == 2) {
            fileToComp = argv[optind];

        } else if (optind == 3) {
            fileToDecomp = argv[optind];
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

        std::string buffer = "";

        while (inputFile2.get(ch)) {
            Cell* foundCell = tree.findCellByChar(root, ch);

            if (foundCell == nullptr) {
                throw std::runtime_error(
                    "Compression error: not found character " + ch);
            }

            buffer += foundCell->getItem().getCode();
        }

        std::string dataBytesToWrite = buffer;

        // escreve os bytes no arquivo
        // utils.writeBytesToFile(outputFile, buffer);
        // utils.printBytes(buffer);

        // escreve byte 0 (ASCII null character) no arquivo de saida, seguido do
        // codigo da arvore
        buffer = "00000000";
        // utils.writeBytesToFile(outputFile, buffer);

        // agora escreve a arvore codificada
        std::string treeCodeToWrite = "";
        tree.codifyTree(tree.getRoot(), treeCodeToWrite);
        tree.setCode(treeCodeToWrite);
        buffer = treeCodeToWrite;

        // escreve o codigo da arvore
        // utils.writeBytesToFile(outputFile, buffer);

        // utils.printBytes(treeCodeToWrite);

        // conta quantos bits tem no dataBytes e no treeCode
        int dataLength = dataBytesToWrite.length();
        int treeCodeLength = treeCodeToWrite.length();

        // escreve esses tamanhos no inicio do arquivo, reservando 32 bits para
        // cada
        utils.writeBytesToFile(outputFile,
                               std::bitset<32>(dataLength).to_string());
        utils.writeBytesToFile(outputFile,
                               std::bitset<32>(treeCodeLength).to_string());

        // agora escreve os dados todos de uma vez, com trailing zeros no final
        buffer = dataBytesToWrite + treeCodeToWrite;
        utils.writeBytesToFile(outputFile, buffer);

        debug(dataLength);
        debug(treeCodeLength);

        utils.printBytes(dataBytesToWrite);
        utils.printBytes(treeCodeToWrite);

        inputFile.close();
        inputFile2.close();
        outputFile.close();
    } else {
        std::ifstream inputFile(fileToDecomp, std::ios::binary);
        std::string dataBytes = "";
        std::string treeCode = "";
        int currentIndex = 0;
        bool isCodeTree = false;

        unsigned long long int decodedDataLength = -1;
        unsigned long long int decodedTreeLength = -1;

        std::string dataLengthBuffer = "";
        std::string treeLengthBuffer = "";

        bool finishedReadingData = false;
        bool finishedReadingTree = false;

        while (!inputFile.eof()) {
            if (finishedReadingData && finishedReadingTree) {
                // ja terminou de ler tudo
                break;
            }

            unsigned char byte;
            inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));

            if (decodedDataLength == -1) {
                // ainda nao leu o tamanho dos dados
                dataLengthBuffer += std::bitset<8>(byte).to_string();

                if (dataLengthBuffer.length() == 32) {
                    decodedDataLength =
                        std::bitset<32>(dataLengthBuffer).to_ullong();
                }

                continue;
            }

            if (decodedTreeLength == -1) {
                // ainda nao leu o tamanho do codigo da arvore
                treeLengthBuffer += std::bitset<8>(byte).to_string();

                if (treeLengthBuffer.length() == 32) {
                    decodedTreeLength =
                        std::bitset<32>(treeLengthBuffer).to_ullong();
                }

                continue;
            }

            // se chegou aqui, ja leu os dois tamanhos. agora sao os bits de
            // dados

            // dois casos possiveis:
            // - posso ler 8 bits de uma vez e salvar (caso 1)
            // - tenho que ler menos que 8 bits (caso 2)

            if (!finishedReadingData) {
                if (decodedDataLength - dataBytes.length() >= 8) {
                    // caso 1
                    dataBytes += std::bitset<8>(byte).to_string();
                } else {
                    // caso 2
                    int diff = decodedDataLength - dataBytes.length();
                    // debug(diff);

                    // tenho que ler somente diff bits. o resto vai para o
                    // treeCode.
                    std::string read8Bits = std::bitset<8>(byte).to_string();

                    dataBytes += read8Bits.substr(0, diff);
                    treeCode += read8Bits.substr(diff, 8);

                    finishedReadingData = true;
                }
            } else {
                // ja finalizou de ler os dados. agora é tudo treeCode
                if (decodedTreeLength - treeCode.length() >= 8) {
                    // caso 1
                    treeCode += std::bitset<8>(byte).to_string();
                } else {
                    // caso 2
                    int diff = decodedTreeLength - treeCode.length();
                    // debug(diff);

                    // tenho que ler somente diff bits
                    std::string read8Bits = std::bitset<8>(byte).to_string();
                    treeCode += read8Bits.substr(0, diff);

                    finishedReadingTree = true;
                }
            }
        }

        // debug(dataBytes.length());
        // debug(treeCode.length());

        // utils.printBytes(dataBytes);
        // utils.printBytes(treeCode);

        HuffmanTree decodedTree = HuffmanTree();
        Cell* decodedRoot = decodedTree.decodifyTree(treeCode, currentIndex);
        decodedTree.setRoot(decodedRoot);
        decodedTree.setCode(treeCode);
        decodedTree.assignHuffmanCodes(decodedRoot, "");

        std::string decodedText = "";
        decodedTree.getDecodedText(dataBytes, decodedText);

        debug(decodedText);

        inputFile.close();
    }

    return 0;
}