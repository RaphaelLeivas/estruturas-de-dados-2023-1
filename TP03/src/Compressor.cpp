#include "../include/Compressor.hpp"

Compressor::Compressor() {}

Compressor::~Compressor() {}

void Compressor::compressFile(std::string inputFile, std::string outputFile) {
    Utils utils = Utils();
    LinkedList list = LinkedList();

    std::ifstream inputStream(inputFile);
    char ch;

    int maxFreq = 0;  // usado na ordenação via counting sort

    while (inputStream.get(ch)) {
        // verifica se ja existe esse caracter
        Cell* foundCell = list.getCellByChar(ch);
        int newFreq;

        if (foundCell == nullptr) {
            // nao existe o caracter. cria um novo e salva
            CellItem newItem = CellItem();
            newItem.setData(ch);
            newFreq = 1;
            newItem.setFrequency(newFreq);

            list.insertEnd(newItem);
        } else {
            // caracter ja existe na lista.
            CellItem currentItem = foundCell->getItem();
            newFreq = currentItem.getFrequency() + 1;
            currentItem.setFrequency(newFreq);

            foundCell->setItem(currentItem);
        }

        if (newFreq >= maxFreq) {
            maxFreq = newFreq;
        }
    }

    if (!list.getSize()) {
        throw std::invalid_argument(
            "ERRO: arquivo de entrada vazio. Não é possível comprimir.");
    }

    // aux que salva a lista original
    LinkedList originalList = LinkedList();

    for (int i = 0; i < list.getSize(); i++) {
        CellItem currentItem = list.getItem(i + 1);
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

        CellItem newItem = CellItem();
        int newFreq =
            left->getItem().getFrequency() + right->getItem().getFrequency();
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
        CellItem item = root->getItem();
        item.setCode("1");
        root->setItem(item);
    } else {
        tree.assignHuffmanCodes(root, "");
    }

    // agora percorre o arquivo de entrada mais um vez. para cada caracter,
    // adicina o correspondente codigo no arquivo de saida
    std::ifstream inputStream2(inputFile);
    std::ofstream outputStream(outputFile, std::ios::binary);

    std::string buffer = "";

    while (inputStream2.get(ch)) {
        Cell* foundCell = tree.findCellByChar(root, ch);

        if (foundCell == nullptr) {
            throw std::runtime_error("Compression error: not found character " +
                                     ch);
        }

        buffer += foundCell->getItem().getCode();
    }

    std::string dataBytesToWrite = buffer;

    // agora escreve a arvore codificada
    std::string treeCodeToWrite = "";
    tree.codifyTree(tree.getRoot(), treeCodeToWrite);
    tree.setCode(treeCodeToWrite);
    buffer = treeCodeToWrite;

    // conta quantos bits tem no dataBytes e no treeCode
    int dataLength = dataBytesToWrite.length();
    int treeCodeLength = treeCodeToWrite.length();

    // escreve esses tamanhos no inicio do arquivo, reservando 32 bits para
    // cada (pode no maximo tamanho 2^32 bits = s^29 bytes = 500 MB)
    utils.writeBytesToFile(outputStream,
                           std::bitset<32>(dataLength).to_string());
    utils.writeBytesToFile(outputStream,
                           std::bitset<32>(treeCodeLength).to_string());

    // agora escreve os dados todos de uma vez, com trailing zeros no final
    buffer = dataBytesToWrite + treeCodeToWrite;
    utils.writeBytesToFile(outputStream, buffer);

    inputStream.close();
    inputStream2.close();
    outputStream.close();
}

void Compressor::decompressFile(std::string inputFile, std::string outputFile) {
    std::ifstream inputStream(inputFile, std::ios::binary);
    std::string dataBytes = "";
    std::string treeCode = "";

    long long int decodedDataLength = -1;
    long long int decodedTreeLength = -1;

    std::string dataLengthBuffer = "";
    std::string treeLengthBuffer = "";

    bool finishedReadingData = false;
    bool finishedReadingTree = false;

    while (!inputStream.eof()) {
        if (finishedReadingData && finishedReadingTree) {
            // ja terminou de ler tudo
            break;
        }

        unsigned char byte;
        inputStream.read(reinterpret_cast<char*>(&byte), sizeof(byte));

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
        // dados; temos dois casos possiveis:
        // - caso 1: posso ler 8 bits de uma vez e salvar
        // - caso 2: tenho que ler menos que 8 bits

        if (!finishedReadingData) {
            if (decodedDataLength - dataBytes.length() >= 8) {
                // caso 1
                dataBytes += std::bitset<8>(byte).to_string();
            } else {
                // caso 2
                int diff = decodedDataLength - dataBytes.length();

                // tenho que ler somente diff bits. o resto vai para o
                // treeCode.
                std::string read8Bits = std::bitset<8>(byte).to_string();

                dataBytes += read8Bits.substr(0, diff);
                treeCode += read8Bits.substr(diff, 8);

                finishedReadingData = true;
            }
        } else {
            // ja finalizou de ler os dados. agora é tudo treeCode, de novo
            // com 2 casos
            if (decodedTreeLength - treeCode.length() >= 8) {
                // caso 1
                treeCode += std::bitset<8>(byte).to_string();
            } else {
                // caso 2
                int diff = decodedTreeLength - treeCode.length();

                // tenho que ler somente diff bits
                std::string read8Bits = std::bitset<8>(byte).to_string();
                treeCode += read8Bits.substr(0, diff);

                finishedReadingTree = true;
            }
        }
    }

    if (!finishedReadingData || !finishedReadingTree) {
        inputStream.close();

        throw std::invalid_argument(
            "ERRO: falha ao ler arquivo de entrada para descomprimir. "
            "Verifique se ele nao esta vazio.");
    }

    long unsigned int currentIndex = 0;

    HuffmanTree decodedTree = HuffmanTree();
    Cell* decodedRoot = decodedTree.decodifyTree(treeCode, currentIndex);
    decodedTree.setRoot(decodedRoot);
    decodedTree.setCode(treeCode);
    decodedTree.assignHuffmanCodes(decodedRoot, "");

    std::string decodedText = "";
    decodedTree.getDecodedText(dataBytes, decodedText);

    // por ultimo, escreve o decodedText no arquivo de saida
    std::ofstream outputStream(outputFile);
    outputStream << decodedText;

    inputStream.close();
    outputStream.close();
}