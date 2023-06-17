#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/ConvexHull.hpp"
#include "../include/Line.hpp"
#include "../include/LinkedList.hpp"
#include "../include/List.hpp"
#include "../include/MyAlgorithms.hpp"
#include "../include/Point.hpp"
#include "../include/customTime.h"

std::string inputFilePath;
bool shouldPrintLines = false;

void parse_args(int argc, char** argv) {
    int c;

    while ((c = getopt(argc, argv, "r")) != EOF) {
        if (c == 'r') {
            shouldPrintLines = true;
        }
    }

    // mais info:
    // https://www.tutorialspoint.com/getopt-function-in-c-to-parse-command-line-arguments
    for (; optind < argc; optind++) {  // when some extra arguments are passed
        inputFilePath = argv[optind];
    }
}

int main(int argc, char** argv) {
    std::cout << std::fixed;
    std::cout.precision(3);

    // usados para calculos os tempos de execucao
    int64_t before;
    int64_t after;

    parse_args(argc, argv);
    MyAlgorithms myAlgorithms;

    std::ifstream input(inputFilePath);
    std::string line;

    // lista encadeada para ler entradas
    LinkedList inputPoints;

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string item;
        char delimiter = ' ';

        List<int>* xyList = new List<int>(2);

        while (std::getline(iss, item, delimiter)) {
            xyList->insertEnd(atoi(item.c_str()));
        }

        int x = xyList->getStart();
        int y = xyList->getEnd();

        Point point;
        point.setX(x);
        point.setY(y);

        // insere o ponto na lista encadeada de pontos
        inputPoints.insertEnd(point);

        delete xyList;
    }

    if (inputPoints.getSize() == 0) {
        std::cout << "Arquivo de entrada vazio ou ele nao existe!" << std::endl;
        return 0;
    }

    // agora monta uma lista normal a partir da encadeada, que usaremos no
    // restante do codigo. isso é feito pois trabalhar com lista encadeada é
    // dificil (muitos ponteiros e nao aguento mais segmentation fault)
    int numberOfPoints = inputPoints.getSize();
    List<Point>* points = new List<Point>(numberOfPoints);

    for (int i = 0; i < numberOfPoints; ++i) {
        points->insertEnd(inputPoints.getByIndex(i));
    }

    // chama o Jarvis para identificar oo pontos do feito convexo
    before = getUnixTimestamp(NANOSECONDS_OPTION);
    List<Point>* convexPoints = myAlgorithms.getConvexPointsByJarvis(points);
    after = getUnixTimestamp(NANOSECONDS_OPTION);
    int64_t jarvisTime = after - before;

    // monta as linhas do feixo
    List<Line>* linesList = new List<Line>(convexPoints->getCurrentSize());

    for (int i = 0; i < convexPoints->getCurrentSize(); ++i) {
        Point p1 = convexPoints->getByIndex(i);
        Point p2;

        if (i == convexPoints->getCurrentSize() - 1) {
            // se é o ultimo, da a volta e termina a linha no ponto de origem
            p2 = convexPoints->getByIndex(0);
        } else {
            p2 = convexPoints->getByIndex(i + 1);
        }

        Line line = Line(p1, p2);

        linesList->insertEnd(line);
    }

    // monta o TAD ConvexHull com essa lista de linhas
    ConvexHull* convexHull = new ConvexHull(linesList);

    std::cout << "FECHO CONVEXO: " << std::endl;
    convexHull->printPoints();
    std::cout << std::endl;

    before = getUnixTimestamp(NANOSECONDS_OPTION);
    convexPoints =
        myAlgorithms.getConvexPointsByGraham(points, GrahamOption::MERGE_SORT);
    after = getUnixTimestamp(NANOSECONDS_OPTION);
    int64_t grahamMergeTime = after - before;

    before = getUnixTimestamp(NANOSECONDS_OPTION);
    convexPoints = myAlgorithms.getConvexPointsByGraham(
        points, GrahamOption::INSERTION_SORT);
    after = getUnixTimestamp(NANOSECONDS_OPTION);
    int64_t grahamInsertionTIme = after - before;

    before = getUnixTimestamp(NANOSECONDS_OPTION);
    convexPoints =
        myAlgorithms.getConvexPointsByGraham(points, GrahamOption::LINEAR_SORT);
    after = getUnixTimestamp(NANOSECONDS_OPTION);
    int64_t grahamLinearTime = after - before;

    std::cout << "GRAHAM+MERGESORT: " << (double)(grahamMergeTime) / pow(10, 9)
              << "s" << std::endl;
    std::cout << "GRAHAM+INSERTIONSORT: "
              << (double)(grahamInsertionTIme) / pow(10, 9) << "s" << std::endl;
    std::cout << "GRAHAM+LINEAR: " << (double)(grahamLinearTime) / pow(10, 9)
              << "s" << std::endl;
    std::cout << "JARVIS: " << (double)(jarvisTime) / pow(10, 9) << "s"
              << std::endl;

    if (shouldPrintLines) {
        std::cout << std::endl;
        convexHull->printLines();
    }

    delete points;
    delete convexPoints;
    delete convexHull;  // ja deleta o linesList

    return 0;
}
