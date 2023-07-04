#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP

#include <fstream>
#include <stdexcept>

#include "Utils.hpp"
#include "LinkedList.hpp"
#include "HuffmanTree.hpp"

class Compressor {
   public:
    Compressor();
    ~Compressor();
    void compressFile(std::string, std::string);
    void decompressFile(std::string, std::string);
};

#endif
