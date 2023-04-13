#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/CircularQueue.hpp"

#define QUEUE_SIZE 5

int main(int argc, char** argv) {
    CircularQueue* q = new CircularQueue(QUEUE_SIZE);

    delete q;
    return 0;
}
