#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include <string>

#include "Cell.hpp"
#include "Utils.hpp"

#define debug(a) std::cout << a << std::endl

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

class HuffmanTree {
   public:
    HuffmanTree();
    ~HuffmanTree();

    void walk(WALK_TYPES);
    void clean();
    void setRoot(Cell*);
    Cell* getRoot();
    void setCode(std::string);
    std::string getCode();
    void assignHuffmanCodes(Cell*, std::string);
    Cell* findCellByChar(Cell*, char);
    void codifyTree(Cell*, std::string&);
    Cell* decodifyTree(std::string&, long unsigned int&);
    bool isLeaf(Cell*);
    void getDecodedText(std::string, std::string&);

   private:
    void cleanRecursive(Cell* p);
    void preOrder(Cell* p);
    void inOrder(Cell* p);
    void postOrder(Cell* p);

    Cell* root;
    std::string code;  // arvore codificada
};

#endif
