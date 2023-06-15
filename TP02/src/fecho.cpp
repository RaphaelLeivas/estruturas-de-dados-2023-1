#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

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
    std::cout << std::fixed;
    std::cout.precision(3);

    parse_args(argc, argv);
    MyAlgorithms myAlgorithms;

    std::ifstream input(inputFilePath);
    std::string line;

    LinkedList pointsList;

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string item;
        char delimiter = ' ';

        // stack auxiliar de 2 posicoes para armazenar as coordenadas x e y no
        // loop do getline
        Stack<int>* stack = new Stack<int>(2);

        while (std::getline(iss, item, delimiter)) {
            stack->push(atoi(item.c_str()));
        }

        int y = stack->pop();
        int x = stack->pop();

        Point point;
        point.setX(x);
        point.setY(y);

        // insere o ponto na lista encadeada de pontos
        pointsList.insertEnd(point);

        delete stack;
    }

    LinkedList convexHull = myAlgorithms.getConvexHullByJarvis(&pointsList);
    convexHull.printList();

    // LinkedList convexHull = myAlgorithms.getConvexHullByGraham(&pointsList);
    // convexHull.printList();

    return 0;
}
