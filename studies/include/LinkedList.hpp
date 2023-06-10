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
    int getByIndex(int);
    int removeEnd();
    bool isEmpty();
    int getSize();

   private:
    Node *head;
    Node *tail;
    int size;
};
