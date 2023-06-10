#include <iostream>
#include <stdexcept>

#define debug(a) std::cout << a << std::endl

struct Node {
    int value;
    struct Node *next;
};

class LinkedList {
   public:
    LinkedList();
    ~LinkedList();
    void printList();
    void insertEnd(int);
    void insertStart(int);
    int getEnd();
    int getStart();
    int removeEnd();
    int removeStart();
    bool isEmpty();

   private:
    Node *head;
    Node *tail;
};
