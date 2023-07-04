#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "Node.hpp"

#define debug(a) std::cout << a << std::endl

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

class BinaryTree {
   public:
    BinaryTree();
    ~BinaryTree();

    void insert(NodeItem item);
    void walk(WALK_TYPES);
    void clean();
    int search(int);
    void remove(int);

   private:
    void insertRecursive(Node*& p, NodeItem item);
    void cleanRecursive(Node* p);
    void byLevel();
    void preOrder(Node* p);
    void inOrder(Node* p);
    void postOrder(Node* p);
    int searchRecursive(Node* p, int);
    void removeRecursive(Node*& p, int);
    void predecessor(Node* q, Node* &r);

    Node* root;
};

#endif
