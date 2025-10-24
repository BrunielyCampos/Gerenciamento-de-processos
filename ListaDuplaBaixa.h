#ifndef _LISTADPULABAIXA_H_
#define _LISTADUPLABAIXA_H_

//confirmar se vai herdar alguma classe

#include <iostream>

struct Node{
    Node * next;
    Node * previous;
};


class ListaDuplaBaixa {
    private:
    Node * head;
    Node * tail;


    public:

    ListaDuplaBaixa();

    ~ListaDuplaBaixa();

    bool isEmpty();
    void clear();

    bool insert();
    bool remove();
    
};

#endif