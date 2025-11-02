#include "ListaDuplaBaixa.h"
#include "Processos.h"

ListaDuplaBaixa::ListaDuplaBaixa(){
    this->head = this->tail = nullptr;
    this->length = 0;
}

ListaDuplaBaixa::~ListaDuplaBaixa(){
    this->clear();
}

bool ListaDuplaBaixa::isEmpty() const{
    return (this->head == nullptr);
}

int ListaDuplaBaixa::getLenght() const{
    return this->length;
}

void ListaDuplaBaixa::clear(){
    if(!isEmpty()){
        NodeBaixa * current = this->head;
        NodeBaixa * aux;

        while(current != nullptr){
            aux = current;
            current = current->next;
            delete aux;
        }
        this->head = this->tail = nullptr;
        this->length = 0;
    }
}

void ListaDuplaBaixa::print(Ordem ordem) const{
    NodeBaixa * current = (ordem == Ordem::PRAFRENTE) ? this->head : this->tail;

    while(current != nullptr){
        cout << "Processo: " << current->processo << " \n";
        current = (ordem == Ordem::PRAFRENTE) ? current->next : current->previous;
    }
}

//ver se vai precisar de um metodo para buscar de trás pra frente

const NodeBaixa * ListaDuplaBaixa::busca(int processo) const{
    NodeBaixa * current = this->head;

    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

bool ListaDuplaBaixa::insert(int processo){

    NodeBaixa * newNode = new NodeBaixa();
    newNode->processo = processo;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    if(isEmpty()){
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

bool ListaDuplaBaixa::remove(int processo){
    if(isEmpty()){ //caso a lista esteja vazia
        cout << "Lista vazia" << "\n";
        return false;
    }
    NodeBaixa* current = this->head;

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
    cout << "O Processo " << processo << " removido" << "\n";

    return true;
}