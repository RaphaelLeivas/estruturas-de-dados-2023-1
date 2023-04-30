#include "../include/BinaryTree.hpp"

BinaryTree::BinaryTree() {
    this->root = NULL;
}

BinaryTree::~BinaryTree() {
    this->erase();
}

void BinaryTree::insert(int item) {
    this->insertRecursive(this->root, item);
}

void BinaryTree::erase() {
    this->eraseRecursive(this->root);
    this->root = NULL;
}

void BinaryTree::insertRecursive(Node* &node, int item) {
    if (node == NULL) {
        node = new Node();
        node->setItem(item);
    } else {
        if (item < node->getItem())
            this->insertRecursive(node->left, item);
        else
            this->insertRecursive(node->right, item);
    }
}

void BinaryTree::walk(WALK_TYPES type) {
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
}

void BinaryTree::preOrder(Node* node) {
    if (node != NULL) {
        node->print();
        this->preOrder(node->left);
        this->preOrder(node->right);
    }
}

void BinaryTree::postOrder(Node* node) {
    if (node != NULL) {
        this->postOrder(node->left);
        this->postOrder(node->right);
        node->print();
    }
}

void BinaryTree::inOrder(Node* node) {
    if (node != NULL) {
        this->inOrder(node->left);
        node->print();
        this->inOrder(node->right);
    }
}

void BinaryTree::byLevel() {
    return;
}

void BinaryTree::eraseRecursive(Node* node) {
    if (node != NULL) {
        this->eraseRecursive(node->left);
        this->eraseRecursive(node->right);

        delete node;
    }
}
