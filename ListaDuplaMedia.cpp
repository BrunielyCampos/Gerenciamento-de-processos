#include "ListaDuplaMedia.h"

ListaDuplaMedia::ListaDuplaMedia(){
    this->head = this->tail = nullptr;
    this->length = 0;
}

ListaDuplaMedia::~ListaDuplaMedia(){
    this->clear();
}

bool ListaDuplaMedia::isEmpty() const{
    return (this->head == nullptr);
}

int ListaDuplaMedia::getLenght() const{
    return this->length;
}

void ListaDuplaMedia::clear(){
    if(!isEmpty()){
        NodeMedia * current = this->head;
        NodeMedia * aux;

        while(current != nullptr){
            aux = current;
            current = current->next;
            delete aux;
        }
        this->head = this->tail = nullptr;
        this->length = 0;
    }
}

void ListaDuplaMedia::print(Ordem ordem) const{
    NodeMedia * current = (ordem == Ordem::PRAFRENTE) ? this->head : this->tail;

    while(current != nullptr){
        cout << "Processo: " << current->processo << " \n";
        current = (ordem == Ordem::PRAFRENTE) ? current->next : current->previous;
    }
}

const NodeMedia * ListaDuplaMedia::busca(int processo) const{
    NodeMedia * current = this->head;

    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

bool ListaDuplaMedia::insert(int processo){

    NodeMedia * newNode = new NodeMedia();
    newNode->processo = processo;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    if(isEmpty){
        head = tail = newNode;
        length++;
        return true;
    }

    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    length++;
    return true;
}

bool ListaDuplaMedia::remove(int processo){
    if(isEmpty()){
        cout << "Lista vazia" << "\n";
        return false;
    }

    NodeMedia * current = this->head;

    while(current != nullptr && current->processo != processo){
        current = current->next;
    }

    if(current == nullptr){
        cout << "Processo nao encontrado" << "\n";
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
    length--;
    cout << "Processo removido com sucesso" << "\n";
    
    return true;
}