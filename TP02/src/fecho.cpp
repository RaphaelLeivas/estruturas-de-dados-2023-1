#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/CircularQueue.hpp"
#include "../include/Line.hpp"
#include "../include/LinkedList.hpp"
#include "../include/MyAlgorithms.hpp"
#include "../include/Point.hpp"

std::string inputFilePath;

void parse_args(int argc, char** argv) {
    // int c;

    // while ((c = getopt(argc, argv, "")) != EOF) {
    //     debug("inside!!");
    //     debug(optind);
    //     if (c == 'f') {
    //         inputFilePath = optind;
    //     }
    // }

    // mais info:
    // https://www.tutorialspoint.com/getopt-function-in-c-to-parse-command-line-arguments
    for (; optind < argc; optind++) {  // when some extra arguments are passed
        inputFilePath = argv[optind];
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    std::ifstream input(inputFilePath);
    std::string line;

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string item;
        char delimiter = ' ';

        // fila de 2 posicoes para armazenar as coordenadas x e y no loop do getline
        CircularQueue<int>* queue = new CircularQueue<int>(3);

        while (std::getline(iss, item, delimiter)) {
            queue->add(atoi(item.c_str()));
        }

        int x = queue->remove();
        int y = queue->remove();

        Point* point = new Point(x, y);

        point->print();

        delete queue;
    }

    // Point* p1 = new Point(0, 0);
    // Point* p2 = new Point(10, 5);

    // Line* l1 = new Line(*p1, *p2);
    // Line* l2 = new Line(*p2, *p1);

    // LinkedList list;

    // list.insertEnd(*l1);
    // list.insertEnd(*l2);

    // list.getByIndex(1).print();
    // list.removeEnd();
    // list.getByIndex(0).print();
    // list.removeEnd();

    // delete l1;
    // delete p1;
    // delete p2;

    return 0;

    // MyAlgorithms* myAlgorithms = new MyAlgorithms();
    // int N = 10;

    // int* arr = new int[N];
    // myAlgorithms->fillArrayWithRandom(arr, N);

    // myAlgorithms->insertionSort(arr, N);

    // myAlgorithms->printArray(arr, N);

    // delete myAlgorithms;
    // delete[] arr;

    // return 0;
}
