#ifndef CONJUNTO_DISJUNTO_HPP
#define CONJUNTO_DISJUNTO_HPP

#define MAX_TAM 10000

class ConjuntoDisjunto {
   private:
	long parent[MAX_TAM];

   public:
    ConjuntoDisjunto();
    ~ConjuntoDisjunto();
    void makeSet(long x);
    void unionSet(long x, long y);
    long findSet(long x);
};

#endif  // CONJUNTO_DISJUNTO_HPP
