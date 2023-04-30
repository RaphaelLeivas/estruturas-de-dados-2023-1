#include "../include/Item.hpp"

template <typename T>
Item<T>::Item(int key, T value) {
    this->key = key;
    this->value = value;
}

template <typename T>
Item<T>::~Item() {}

template <typename T>
T Item<T>::getValue() {
    return this->value;
}

template <typename T>
void Item<T>::setValue(T value) {
    this->value = value;
}

template <typename T>
int Item<T>::getKey() {
    return this->key;
}

template <typename T>
void Item<T>::setKey(int key) {
    this->key = key;
}

template <typename T>
void Item<T>::print() {
    std::cout << "--- ITEM ---" << std::endl;
    std::cout << "Key: " << this->key << std::endl;
    std::cout << "Value: " << this->value << std::endl;
    std::cout << "------------" << std::endl;
}

template class Item<double>;
template class Item<std::string>;
template class Item<int>;
template class Item<char>;
