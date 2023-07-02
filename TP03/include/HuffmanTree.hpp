#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include <string>
#include "Cell.hpp"

#define debug(a) std::cout << a << std::endl

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

class HuffmanTree {
   public:
    HuffmanTree();
    ~HuffmanTree();

    void insert(NodeItem item);
    void walk(WALK_TYPES);
    void clean();
    int search(int);
    void remove(int);
    void setRoot(Cell*);
    Cell* getRoot();
    void assignHuffmanCodes(Cell*, std::string);
    Cell* findCellByChar(Cell*, char);

   private:
    void insertRecursive(Cell*& p, NodeItem item);
    void cleanRecursive(Cell* p);
    void byLevel();
    void preOrder(Cell* p);
    void inOrder(Cell* p);
    void postOrder(Cell* p);
    int searchRecursive(Cell* p, int);
    void removeRecursive(Cell*& p, int);
    void predecessor(Cell* q, Cell* &r);

    Cell* root;
};

#endif
