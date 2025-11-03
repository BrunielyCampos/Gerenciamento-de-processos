#include "ListaDuplaMedia.h"

ListaDuplaMedia::ListaDuplaMedia(){
    this->head = this->tail = nullptr;
    this->length = 0;
}

ListaDuplaMedia::~ListaDuplaMedia(){
    this->clear();
}

bool ListaDuplaMedia::isEmpty() const{
     return head == nullptr;
}

int ListaDuplaMedia::getLenght() const{
    return this->length;
}

void ListaDuplaMedia::clear(){
    while (!isEmpty()) {
        Processos* p = remove(p); 
        delete p; 
    }
}

void ListaDuplaMedia::print() const {
    NodeMedia* current = head;
    if (isEmpty()) {
        std::cout << "   (vazia)\n";
        return;
    }
    while (current != nullptr) {
        std::cout << "   -> Processo ID: " << current->processo->IdProcessos() << "\n";
        current = current->next;
    }
}

NodeMedia * ListaDuplaMedia::busca(Processos* processo) const{
    NodeMedia * current = this->head;

    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

Processos* ListaDuplaMedia::insert(Processos* processo){

    NodeMedia * newNode = new NodeMedia();
    newNode->processo = processo;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    if(isEmpty()){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        length++;
        return processo;
    }
}

Processos* ListaDuplaMedia::remove(Processos* processo){
     if (isEmpty()) {
        return nullptr;
    }
    
    NodeMedia* temp = head;
    Processos* processoRemovido = temp->processo;

    head = head->next; // O novo 'head' é o segundo elemento
    
    if (head != nullptr) {
        head->previous = nullptr; // O novo 'head' não tem ninguém antes
    } else {
        // Se a lista ficou vazia, o 'tail' também deve ser nulo
        tail = nullptr;
    }
    
    delete temp; // Libera a memória do nó removido
    length--;
    return processoRemovido;
}

