class Stack {
   public:
    Stack(unsigned int size);
    ~Stack();
    int pop();
    void push(int value);
    bool isEmpty();
    void destroy();
    unsigned int getSize();

   private:
    unsigned int size;
    CircularQueue* queue;
}

Stack::Stack(unsigned int size) {
    this->size = size;
    this->queue = new CircularQueue(size);
}

Stack : ~Stack() {}

void Stack : destroy() {
    // chama o metodo this->queue->destroyQueue() se ele estiver implementado
    this->queue->emptyQueue();
    delete this->queue;
}

unsigned int Stack::getSize() { return this->size; }

void Stack::push(int value) { this->queue->insert(value); }

int Stack::pop() { this->queue->removeLast(); }

bool Stack::isEmpty() { return this->getSize() == 0; }
