#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/LinkedList.hpp"

int main(int argc, char** argv) {
    LinkedList* list = new LinkedList();

    list->insertEnd(10);
    list->insertEnd(20);
    list->insertEnd(30);
    list->insertEnd(33);

        std::cout << list->getByIndex(0) << std::endl;
    std::cout << list->getByIndex(1) << std::endl;
    std::cout << list->getByIndex(2) << std::endl;
    std::cout << list->getByIndex(3) << std::endl;


    list->removeEnd();
    list->removeEnd();
    list->removeEnd();
    list->removeEnd();


    // list->removeEnd();

    list->insertEnd(125);
    // list->removeEnd();

    std::cout << list->getStart() << std::endl;
    std::cout << list->getSize() << std::endl;

    std::cout << list->getByIndex(0) << std::endl;


    delete list;

    return 0;
}
