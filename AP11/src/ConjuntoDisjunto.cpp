#include "ConjuntoDisjunto.hpp"

ConjuntoDisjunto::ConjuntoDisjunto() {
    this->parent = new long[MAX_TAM];
    this->rank = new long[MAX_TAM];
    this->hasRankOptimazion = true;
}

ConjuntoDisjunto::~ConjuntoDisjunto() {
    delete[] parent;
    delete[] rank;
}

void ConjuntoDisjunto::makeSet(long x) {
    // cria um novo conjunto cujo único membro é x
    parent[x] = x;
}

void ConjuntoDisjunto::unionSet(long x, long y) {
    // une os conjuntos dinâmicos que contêm x e y, digamos Sx e Sy, em um novo
    // conjunto que é a união desses dois conjuntos
    int xset = this->findSet(x);
    int yset = this->findSet(y);

    // se ja estao no mesmo conjunto
    if (xset == yset) return;

    if (hasRankOptimazion) {
        // verificacao dos ranks
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    } else {
        parent[xset] = yset;
    }
}

long ConjuntoDisjunto::findSet(long x) {
    // retorna um ponteiro para o representante do (único) conjunto que contém x
    if (parent[x] == x) return x;
    return this->findSet(parent[x]);
}
