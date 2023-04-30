#include "../include/Node.hpp"

template <typename T>
Node<T>::Node() {
    Item<T>* item = new Item<T>();
    item->setKey(-1);

    this->item = item;
    this->left = NULL;
    this->right = NULL;
}

template <typename T>
Node<T>::~Node() {}

template <typename T>
Item<T>* Node<T>::getItem() {
    return this->item;
}

template class Node<double>;
template class Node<std::string>;
template class Node<int>;
template class Node<char>;
