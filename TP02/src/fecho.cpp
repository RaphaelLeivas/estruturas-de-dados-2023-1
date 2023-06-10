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
    MyAlgorithms* myAlgorithms = new MyAlgorithms();

    std::ifstream input(inputFilePath);
    std::string line;

    LinkedList pointsList;

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

        Point point;
        point.setX(x);
        point.setY(y);

        // insere o ponto na lista encadeada de pontos
        pointsList.insertEnd(point);

        delete queue;
    }

    pointsList.printList();

    // com a lista de pontos pronta, chama o algoritmo do Jarvis
    LinkedList convexHull = myAlgorithms->getConvexHullByJarvis(pointsList);

    convexHull.printList();

    // Point* p1 = new Point(0, 1);
    // Point* p2 = new Point(12, 25);

    // LinkedList list;

    // list.insertEnd(*p1);
    // list.insertEnd(*p2);

    // list.getByIndex(1).print();
    // list.removeEnd();
    // list.getByIndex(0).print();
    // list.removeEnd();

    // delete p1;
    // delete p2;

    return 0;

    // int N = 10;

    // int* arr = new int[N];
    // myAlgorithms->fillArrayWithRandom(arr, N);

    // myAlgorithms->insertionSort(arr, N);

    // myAlgorithms->printArray(arr, N);

    // delete myAlgorithms;
    // delete[] arr;

    // return 0;
}
