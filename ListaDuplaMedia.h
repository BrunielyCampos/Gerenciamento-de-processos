#ifndef _LISTADUPLAMEDIA_H_
#define _LISTADUPLAMEDIA_H_

//confirmar se vai herdar alguma classe

#include <iostream>


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
    ListaDuplaMedia(const ListaDuplaMedia & list);

    ~ListaDuplaMedia();

    bool isEmpty();
    int getLenght() const;
    
    void clear();
    void print(Ordem ordem = Ordem::PRAFRENTE) const;

    const NodeMedia * busca(int processo) const;
    bool insert(int processo);
    bool remove(int processo);
    
    /*const ListaDuplaMedia & operador(const ListaDuplaMedia & list);
    const ListaDuplaMedia & operador(const ListaDuplaMedia & list);
    */
    
};

#endif