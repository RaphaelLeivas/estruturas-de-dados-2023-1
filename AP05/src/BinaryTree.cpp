#include "../include/BinaryTree.hpp"

int getRandomInteger() {
    using u32 = uint_least32_t;
    using engine = std::mt19937;
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(1, 100);

    return distribute(generator);
}

BinaryTree::BinaryTree() { this->root = NULL; }

BinaryTree::~BinaryTree() { this->erase(); }

void BinaryTree::insert(int item) { this->insertRecursive(this->root, item); }

void BinaryTree::erase() {
    this->eraseRecursive(this->root);
    this->root = NULL;
}

void BinaryTree::fillWithRandom() {
    for (int i = 0; i < RANDOM_TREE_SIZE; ++i) {
        this->insert(getRandomInteger());
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
    CircularQueue<int>* q = new CircularQueue<int>(RANDOM_TREE_SIZE);

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
    CircularQueue<Node*>* queue = new CircularQueue<Node*>(RANDOM_TREE_SIZE);
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