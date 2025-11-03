#ifndef _LISTADPULABAIXA_H_
#define _LISTADUPLABAIXA_H_

#include "Processos.h"

#include <iostream>

using std::cout;

struct NodeBaixa{
    NodeBaixa * next;
    Processos* processo; //processo
    NodeBaixa * previous;
};

enum Ordem1{
    B_PRAFRENTE,
    B_PRATRAS
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
    void print(Ordem1 ordem = Ordem1::B_PRAFRENTE) const;

    const NodeBaixa * busca(Processos* processo) const;
    bool insert(Processos* processo);
    Processos* remove();

};

#endif