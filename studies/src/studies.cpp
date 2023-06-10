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

    list->printList();

    std::cout << list->getStart() << std::endl;
    std::cout << list->getEnd() << std::endl;

    list->removeEnd();
    list->removeEnd();
    // list->removeEnd();
    // list->removeEnd();
    // list->removeEnd();

    list->insertStart(10);

    std::cout << list->getEnd() << std::endl;

    delete list;

    return 0;
}
