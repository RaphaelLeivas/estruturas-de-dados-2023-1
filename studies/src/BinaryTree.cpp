#include "../include/BinaryTree.hpp"

BinaryTree::BinaryTree() { this->root = nullptr; }

BinaryTree::~BinaryTree() { this->clean(); }

void BinaryTree::insert(NodeItem item) {
    this->insertRecursive(this->root, item);
}

void BinaryTree::remove(int freq) {
    return this->removeRecursive(this->root, freq);
}

void BinaryTree::clean() {
    this->cleanRecursive(this->root);
    this->root = nullptr;
}

int BinaryTree::search(int freq) {
    return this->searchRecursive(this->root, freq);
}

void BinaryTree::walk(WALK_TYPES type) {
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

        case WALK_TYPES::BY_LEVEL:
            this->byLevel();
            break;

        default:
            this->inOrder(this->root);
            break;
    }
    
    std::cout << "------------" << std::endl;
    std::cout << "WALK ENDED" << std::endl;
}

void BinaryTree::insertRecursive(Node*& p, NodeItem item) {
    if (p == nullptr) {
        p = new Node();
        p->setItem(item);
    } else {
        if (item.getFrequency() <= p->getItem().getFrequency())
            this->insertRecursive(p->left, item);
        else
            this->insertRecursive(p->right, item);
    }
}

void BinaryTree::removeRecursive(Node*& p, int freq) {
    Node* aux;

    if (p == nullptr) {
        throw("Item nao está presente");
    }
    if (freq < p->getItem().getFrequency())
        return this->removeRecursive(p->left, freq);
    else if (freq > p->getItem().getFrequency())
        return this->removeRecursive(p->right, freq);
    else {
        if (p->right == nullptr) {
            aux = p;
            p = p->left;
            delete aux;
        } else if (p->left == nullptr) {
            aux = p;
            p = p->right;
            delete aux;
        } else
            this->predecessor(p, p->left);
    }
}

void BinaryTree::predecessor(Node* q, Node*& r) {
    if (r->right != nullptr) {
        this->predecessor(q, r->right);
        return;
    }

    q->item = r->item;
    q = r;
    r = r->left;

    delete q;
}

void BinaryTree::preOrder(Node* p) {
    if (p != nullptr) {
        p->getItem().print();
        this->preOrder(p->left);
        this->preOrder(p->right);
    }
}

void BinaryTree::inOrder(Node* p) {
    if (p != nullptr) {
        this->inOrder(p->left);
        p->getItem().print();
        this->inOrder(p->right);
    }
}

void BinaryTree::postOrder(Node* p) {
    if (p != nullptr) {
        this->postOrder(p->left);
        this->postOrder(p->right);
        p->getItem().print();
    }
}

void BinaryTree::byLevel() {
    // implementar caso necessario
}

void BinaryTree::cleanRecursive(Node* p) {
    if (p != nullptr) {
        this->cleanRecursive(p->right);
        this->cleanRecursive(p->left);
        delete p;
    }
}

int BinaryTree::searchRecursive(Node* p, int freq) {
    int aux;

    if (p == nullptr) {
        aux = -1;  // item nao presente
        return aux;
    }

    if (freq < p->getItem().getFrequency()) {
        return this->searchRecursive(p->left, freq);
    } else if (freq > p->getItem().getFrequency()) {
        return this->searchRecursive(p->right, freq);
    } else {
        return p->getItem().getFrequency();
    }
}
