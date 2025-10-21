#ifndef _LISTADUPLAMEDIA_H_
#define _LISTADUPLAMEDIA_H_

//confirmar se vai herdar alguma classe

#include <iostream>


struct Node{
    Node * next;
    Node * previous;
};



class ListaDuplaMedia {
    private:
    Node * head;
    Node * tail;

    public:
    ListaDuplaMedia();

    ~ListaDuplaMedia();


};

#endif