#include "ConjuntoDisjunto.hpp"

// defaults
ConjuntoDisjunto::ConjuntoDisjunto() {}
ConjuntoDisjunto::~ConjuntoDisjunto() {}

void ConjuntoDisjunto::makeSet(long x) {
    // cria um novo conjunto cujo único membro é x
    parent[x] = x;
}

void ConjuntoDisjunto::unionSet(long x, long y) {
    // une os conjuntos dinâmicos que contêm x e y, digamos Sx e Sy, em um novo
    // conjunto que é a união desses dois conjuntos
    int m = this->findSet(x);
    int n = this->findSet(y);
    parent[m] = n;
}

long ConjuntoDisjunto::findSet(long x) {
    // retorna um ponteiro para o representante do (único) conjunto que contém x
    if (parent[x] == x)  
        return x;
    return this->findSet(parent[x]);  
}
