#include "ListaDuplaBaixa.h"

ListaDuplaBaixa::ListaDuplaBaixa(){
    head = nullptr;
    tail = nullptr;
}

ListaDuplaBaixa::~ListaDuplaBaixa(){
    this->clear();
}

bool ListaDuplaBaixa::isEmpty() const{
    return (head == nullptr);
}

int ListaDuplaBaixa::getLenght() const{
    return this->lenght;
}

void ListaDuplaBaixa::clear(){
    if(!isEmpty()){
        Node * current = this->head;
        Node * aux;

        while(current != nullptr){
            aux = current;
            current = current->next;
            delete aux;
        }
        this->head = this->tail = nullptr;
        this->lenght = 0;
    }
}

bool ListaDuplaBaixa::insert(int i){

}

bool ListaDuplaBaixa::remove(int i){

}