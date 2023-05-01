#include "../include/BinaryTree.hpp"

int getRandomInteger() {
    using u32 = uint_least32_t;
    using engine = std::mt19937;
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 9);

    return distribute(generator);
}

BinaryTree::BinaryTree() { this->root = NULL; }

BinaryTree::~BinaryTree() { this->erase(); }

void BinaryTree::insert(int item) { this->insertRecursive(this->root, item); }

void BinaryTree::erase() {
    this->eraseRecursive(this->root);
    this->root = NULL;
}

void BinaryTree::fillWithRandom(int n) {
    // int* array = new int[n];

    // // gera um array contendo 0 a n - 1
    // for (int i = 0; i < n; ++i) {
    //     array[i] = i;
    // }

    // // reorganiza aleatoriamente o array
    // for (int i = 0; i < n; ++i) {
    //     int r = getRandomInteger();

    //     // troca eles
    //     int tmp = array[r];
    //     array[i] = tmp;
    //     array[r] = array[i];
    // }

    // for (int i = 0; i < n; i++) {
    //     std::cout << array[i] << " ";
    // }
    // std::cout << std::endl;

    // gera array aleatorio comn as chaves de 0 a n - 1
    int array[n] = {2, 0, 9, 5, 4, 3, 7, 6, 8, 1};

    // prenche a arvore com essas chaves

    for (int i = 0; i < n; i++) {
        this->insert(array[i]);
    }
}

void BinaryTree::insertRecursive(Node*& node, int item) {
    if (node == NULL) {
        node = new Node();
        node->setItem(item);
    } else {
        if (item < node->getItem())
            this->insertRecursive(node->left, item);
        else
            this->insertRecursive(node->right, item);
    }
}

CircularQueue<int>* BinaryTree::walk(WALK_TYPES type) {
    // fila para salvar a ordem de percurso
    CircularQueue<int>* q = new CircularQueue<int>(AUX_QUEUE_SIZE);

    switch (type) {
        case WALK_TYPES::IN_ORDER:
            this->inOrder(this->root, q);
            break;

        case WALK_TYPES::PRE_ORDER:
            this->preOrder(this->root, q);
            break;

        case WALK_TYPES::POST_ORDER:
            this->postOrder(this->root, q);
            break;

        case WALK_TYPES::BY_LEVEL:
            this->byLevel();
            break;

        default:
            this->inOrder(this->root, q);
            break;
    }

    return q;
}

void BinaryTree::preOrder(Node* node, CircularQueue<int>*& q) {
    if (node != NULL) {
        q->add(node->getItem());
        this->preOrder(node->left, q);
        this->preOrder(node->right, q);
    }
}

void BinaryTree::postOrder(Node* node, CircularQueue<int>*& q) {
    if (node != NULL) {
        this->postOrder(node->left, q);
        this->postOrder(node->right, q);
        q->add(node->getItem());
    }
}

void BinaryTree::inOrder(Node* node, CircularQueue<int>*& q) {
    if (node != NULL) {
        this->inOrder(node->left, q);
        q->add(node->getItem());
        this->inOrder(node->right, q);
    }
}

void BinaryTree::byLevel() {
    // usa fila auxiliar
    CircularQueue<Node*>* queue = new CircularQueue<Node*>(AUX_QUEUE_SIZE);
    queue->add(this->root);

    while (!queue->isEmpty()) {
        Node* node = queue->remove();
        if (node != NULL) {
            node->print();
            queue->add(node->left);
            queue->add(node->right);
        }
    }

    delete queue;
}

void BinaryTree::eraseRecursive(Node* node) {
    if (node != NULL) {
        this->eraseRecursive(node->left);
        this->eraseRecursive(node->right);

        delete node;
    }
}
