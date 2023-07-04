#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/Compressor.hpp"

bool isCompression = false;

std::string inputFile;
std::string outputFile;

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "cd")) != EOF) {
        if (c == 'c') {
            isCompression = true;
        }
        if (c == 'd') {
            isCompression = false;
        }
    }

    // https://www.tutorialspoint.com/getopt-function-in-c-to-parse-command-line-arguments
    for (; optind < argc; optind++) {
        if (optind == 2) {
            inputFile = argv[optind];
        } else if (optind == 3) {
            outputFile = argv[optind];
        }
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);
    Compressor compressor = Compressor();

    if (isCompression) {
        compressor.compressFile(inputFile, outputFile);
    } else {
        compressor.decompressFile(inputFile, outputFile);
    }

    return 0;
}