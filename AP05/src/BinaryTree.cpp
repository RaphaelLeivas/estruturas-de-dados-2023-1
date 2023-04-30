#include "../include/BinaryTree.hpp"

template <typename T>
BinaryTree<T>::BinaryTree() {
    this->root = NULL
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    this->erase();
}

template <typename T>
void BinaryTree<T>::insert(Item<T> item) {
    this->insertRecursive(this->root, item);
}

template <typename T>
void BinaryTree<T>::erase() {
    this->eraseRecursive(this->root);
    this->root = NULL;
}

template <typename T>
void BinaryTree<T>::insertRecursive(Node<T>* node, Item<T> item) {
    if (node == NULL) {
        node = new Node<T>();
        node->setItem(item);
    } else {
        if (item.getKey() < node->item.getKey())
            this->insertRecursive(node->left, item);
        else
            this->insertRecursive(node->right, item);
    }
}

template <typename T>
void BinaryTree<T>::walk(WALK_TYPES type) {
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

template <typename T>
void BinaryTree<T>::preOrder(Node<T>* node) {
    if (node != NULL) {
        node->getItem()->print();
        this->preOrder(node->left);
        this->preOrder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::postOrder(Node<T>* node) {
    if (node != NULL) {
        this->postOrder(node->left);
        this->postOrder(node->right);
        node->getItem()->print();
    }
}

template <typename T>
void BinaryTree<T>::inOrder(Node<T>* node) {
    if (node != NULL) {
        this->inOrder(node->left);
        node->getItem()->print();
        this->inOrder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::eraseRecursive(Node<T>* node) {
    if (node != NULL) {
        this->eraseRecursive(node->left);
        this->eraseRecursive(node->right);

        delete node;
    }
}


template class BinaryTree<double>;
template class BinaryTree<std::string>;
template class BinaryTree<int>;
template class BinaryTree<char>;
