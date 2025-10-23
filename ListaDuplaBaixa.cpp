#include "ListaDuplaBaixa.h"

ListaDuplaBaixa::ListaDuplaBaixa(){
    this->head = this->tail = nullptr;
    this->lenght = 0;
}

ListaDuplaBaixa::ListaDuplaBaixa(const ListaDuplaBaixa & list){

}

ListaDuplaBaixa::~ListaDuplaBaixa(){
    this->clear();
}

bool ListaDuplaBaixa::isEmpty() const{
    return (this->head == nullptr);
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

void ListaDuplaBaixa::print(Ordem ordem) const{
    Node * current = (ordem == Ordem::PRAFRENTE) ? this->head : this->tail;

    while(current != nullptr){
        cout << current->processo << " ";
        current = (ordem == Ordem::PRAFRENTE) ? current->next : current->previous;
    }
}

const Node * ListaDuplaBaixa::busca(int processo) const{
    Node * current = this->head;

    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

bool ListaDuplaBaixa::insert(int processo){
    Node * current = this->head;

    while(current != nullptr && current->processo < processo){
        current = current->next;
    }
    if(current != nullptr && current-> processo == processo){
        return false;
    }else{
        Node * newNode = new Node();
        newNode->processo = processo;

        if(current == this->head){
            newNode->next = this->head;
            this->head = newNode;
            newNode->previous = nullptr;
            if(newNode->next != nullptr){
                newNode->next->previous = newNode;
            }else{
                this->tail = newNode;
            }
        }
        return true;
    }
}

bool ListaDuplaBaixa::remove(int processo){ //revisitar para colocar as prioridades
    /*Node* current = this->head;

    while(current != nullptr && current->processo != processo){
        current = current->next;
    }
    if(current == nullptr){
        cout << "Valor nao encontrado" << "\n";
        return false;
    }
    if(current->previous != nullptr){
        current->previous->next = current->next;
    }else{
        head = current->next;
    }

    if(current->next != nullptr){
        current->next->previous = current->previous;
    }else{
        tail = current->previous;
    }

    delete current;
    cout << "O valor " << processo << " foi removido" << "\n";
    return true;*/
}