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

void ListaDuplaBaixa::print(Ordem1 ordem) const{
    NodeBaixa * current = (ordem == Ordem1::B_PRAFRENTE) ? this->head : this->tail;

    while(current != nullptr){
        cout << "Processo: " << current->processo << " \n";
        current = (ordem == Ordem1::B_PRAFRENTE) ? current->next : current->previous;
    }
}

//ver se vai precisar de um metodo para buscar de trás pra frente

const NodeBaixa * ListaDuplaBaixa::busca(Processos* processo) const{
    NodeBaixa * current = this->head;

    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

bool ListaDuplaBaixa::insert(Processos* processo){

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

Processos* ListaDuplaBaixa::remove(){
     if (isEmpty()) {
        return nullptr;
    }
    
    NodeBaixa* temp = head;
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