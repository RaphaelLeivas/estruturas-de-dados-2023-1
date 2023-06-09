#include "../include/HuffmanTree.hpp"

static Utils utils = Utils();

HuffmanTree::HuffmanTree() { this->root = nullptr; }

HuffmanTree::~HuffmanTree() {}

void HuffmanTree::setRoot(Cell* root) { this->root = root; }

Cell* HuffmanTree::getRoot() { return this->root; }

void HuffmanTree::setCode(std::string code) { this->code = code; }

std::string HuffmanTree::getCode() { return this->code; }

void HuffmanTree::assignHuffmanCodes(Cell* root, std::string str) {
    if (!root) {
        return;
    }

    if (root->getItem().getData() != 0) {
        CellItem item = root->getItem();
        item.setCode(str);
        root->setItem(item);
    }

    this->assignHuffmanCodes(root->left, str + "0");
    this->assignHuffmanCodes(root->right, str + "1");
}

Cell* HuffmanTree::findCellByChar(Cell* root, char c) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->getItem().getData() == c) {
        return root;
    }

    Cell* result = this->findCellByChar(root->left, c);
    if (result) {
        return result;
    }
    return this->findCellByChar(root->right, c);
}

// retorna sequencia de bits que representam a arvore
void HuffmanTree::codifyTree(Cell* p, std::string& str) {
    if (p != nullptr) {
        if (this->isLeaf(p)) {
            // gera bit 1 + 8-bit do char
            char c = p->getItem().getData();
            str = str + "1" + utils.charTo8Bits(c).to_string();
        } else {
            str = str + "0";
            this->codifyTree(p->left, str);
            this->codifyTree(p->right, str);
        }
    }
}

Cell* HuffmanTree::decodifyTree(std::string& encodedTree, long unsigned int& currentIndex) {
    if (currentIndex >= encodedTree.size()) {
        return nullptr;
    }

    if (encodedTree[currentIndex] == '1') {
        // folha
        std::string symbolBits = encodedTree.substr(currentIndex + 1, 8);
        char data = static_cast<char>(std::bitset<8>(symbolBits).to_ulong());
        currentIndex += 9; 

        Cell* leafNode = new Cell();
        CellItem newItem = CellItem();
        newItem.setData(data);
        leafNode->setItem(newItem);
        leafNode->left = nullptr;
        leafNode->right = nullptr;

        return leafNode;
    } else {
        // no interno
        currentIndex++; 

        Cell* internalNode = new Cell();
        internalNode->left = this->decodifyTree(encodedTree, currentIndex);
        internalNode->right = this->decodifyTree(encodedTree, currentIndex);

        return internalNode;
    }
}

void HuffmanTree::getDecodedText(std::string dataBytes,
                                 std::string& decodedText) {
    Cell* currentNode = this->root;

    if (currentNode == nullptr) {
        throw std::invalid_argument(
            "currentNode is nullptr in getDecodedText !");
    }

    for (char bit : dataBytes) {
        if (currentNode == nullptr) {
            continue;
        }

        if (bit == '0') {
            currentNode = currentNode->left;
        } else if (bit == '1') {
            currentNode = currentNode->right;
        }

        if (this->isLeaf(currentNode)) {
            decodedText += currentNode->getItem().getData();
            currentNode = this->root;
        }
    }
}

void HuffmanTree::clean() {
    this->cleanRecursive(this->root);
    this->root = nullptr;
}

void HuffmanTree::walk(WALK_TYPES type) {
    std::cout << "WALK STARTED" << std::endl;
    std::cout << "------------" << std::endl;

    switch (type) {
        case WALK_TYPES::IN_ORDER:
            this->inOrder(this->root);
            break;

        case WALK_TYPES::PRE_ORDER:
            this->preOrder(this->root);
            break;

        case WALK_TYPES::POST_ORDER:
            this->postOrder(this->root);
            break;

        default:
            this->inOrder(this->root);
            break;
    }

    std::cout << "------------" << std::endl;
    std::cout << "WALK ENDED" << std::endl;
}

void HuffmanTree::preOrder(Cell* p) {
    if (p != nullptr) {
        p->getItem().print();
        this->preOrder(p->left);
        this->preOrder(p->right);
    }
}

void HuffmanTree::inOrder(Cell* p) {
    if (p != nullptr) {
        this->inOrder(p->left);
        p->getItem().print();
        this->inOrder(p->right);
    }
}

void HuffmanTree::postOrder(Cell* p) {
    if (p != nullptr) {
        this->postOrder(p->left);
        this->postOrder(p->right);
        p->getItem().print();
    }
}

void HuffmanTree::cleanRecursive(Cell* p) {
    if (p != nullptr) {
        this->cleanRecursive(p->right);
        this->cleanRecursive(p->left);
        delete p;
    }
}

bool HuffmanTree::isLeaf(Cell* cell) {
    if (cell == nullptr) {
        return false; // gambiarra
    }

    return cell->left == nullptr && cell->right == nullptr;
}
