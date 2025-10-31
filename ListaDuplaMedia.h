#ifndef _LISTADUPLAMEDIA_H_
#define _LISTADUPLAMEDIA_H_

#include "Processos.h"

#include <iostream>

using std::cout;

struct NodeMedia{
    NodeMedia * next;
    int processo;
    NodeMedia * previous;
};

enum Ordem{
    PRAFRENTE,
    PRATRAS
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
    void print(Ordem ordem = Ordem::PRAFRENTE) const;

    const NodeMedia * busca(int processo) const;
    bool insert(int processo);
    bool remove(int processo);
    
};

#endif