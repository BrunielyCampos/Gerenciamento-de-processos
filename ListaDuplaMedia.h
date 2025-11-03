#ifndef _LISTADUPLAMEDIA_H_
#define _LISTADUPLAMEDIA_H_

#include "Processos.h"

#include <iostream>

using std::cout;

struct NodeMedia{
    NodeMedia * next;
    Processos* processo;
    NodeMedia * previous;
};

enum Ordem2{
    M_PRAFRENTE,
    M_PRATRAS
};

class ListaDuplaMedia {
    private:
    NodeMedia * head;
    NodeMedia * tail;
    int length;

    public:
    ListaDuplaMedia();

    ~ListaDuplaMedia();

    bool isEmpty() const;
    int getLenght() const;
    
    void clear();

    NodeMedia * busca(Processos* processo) const;
    Processos* insert(Processos* processo);
    Processos* remove(Processos* processo);
    void print() const;
};

#endif