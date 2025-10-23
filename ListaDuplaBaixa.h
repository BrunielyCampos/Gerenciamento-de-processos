#ifndef _LISTADPULABAIXA_H_
#define _LISTADUPLABAIXA_H_

//confirmar se vai herdar alguma classe

#include <iostream>

using std::cout;

struct Node{
    Node * next;
    Node * previous;
};

enum Ordem{
    PRAFRENTE,
    PRATRAS
};


class ListaDuplaBaixa {
    private:
    Node * head;
    Node * tail;
    int lenght;


    public:
    ListaDuplaBaixa();
    ListaDuplaBaixa(const ListaDuplaBaixa & list);

    ~ListaDuplaBaixa();

    bool isEmpty() const;
    int getLenght() const;

    void clear();
    void print(Ordem ordem = Ordem::PRAFRENTE) const;

    const Node * busca(int i) const;
    bool insert(int i);
    bool remove(int i);
    
    void concatenate (const ListaDuplaBaixa & list);

    /*const ListaDuplaBaixa & operador=(const ListaDuplaBaixa & list);
    const ListaDuplaBaixa & operador+(const ListaDuplaBaixa & list);
    */
};

#endif