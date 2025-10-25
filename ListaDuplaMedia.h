#ifndef _LISTADUPLAMEDIA_H_
#define _LISTADUPLAMEDIA_H_

//confirmar se vai herdar alguma classe

#include <iostream>


struct Node{
    Node * next;
    int processo;
    Node * previous;
};

enum Ordem{
    PRAFRENTE,
    PRATRAS
};

class ListaDuplaMedia {
    private:
    Node * head;
    Node * tail;
    int lenght;

    public:
    ListaDuplaMedia();
    ListaDuplaMedia(const ListaDuplaMedia & list);

    ~ListaDuplaMedia();

    bool isEmpty();
    int getLenght() const;
    
    void clear();
    void print(Ordem ordem = Ordem::PRAFRENTE) const;

    const Node * busca(int processo) const;
    bool insert(int processo);
    bool remove(int processo);

    void concatenate (const ListaDuplaMedia & list);
    
    /*const ListaDuplaMedia & operador(const ListaDuplaMedia & list);
    const ListaDuplaMedia & operador(const ListaDuplaMedia & list);
    */
    
};

#endif