#ifndef _LISTADPULABAIXA_H_
#define _LISTADUPLABAIXA_H_

#include "Processos.h"

#include <iostream>

using std::cout;

struct NodeBaixa{
    NodeBaixa * next;
    int processo; //processo
    NodeBaixa * previous;
};

enum Ordem{
    PRAFRENTE,
    PRATRAS
};


class ListaDuplaBaixa {
    private:
    NodeBaixa * head;
    NodeBaixa * tail;
    int length;

    public:
    ListaDuplaBaixa();

    ~ListaDuplaBaixa();

    bool isEmpty() const;
    int getLenght() const;

    void clear();
    void print(Ordem ordem = Ordem::PRAFRENTE) const;

    const NodeBaixa * busca(int processo) const;
    bool insert(int processo);
    bool remove(int processo);

};

#endif