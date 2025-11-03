#include "ListaDuplaMedia.h"

// Construtor - Inicializa uma lista vazia
ListaDuplaMedia::ListaDuplaMedia(){
    this->head = this->tail = nullptr;
    this->length = 0;
}

// Destrutor - Limpa a lista antes de destruí-la
ListaDuplaMedia::~ListaDuplaMedia(){
    this->clear();
}

// Verifica se a lista está vazia
bool ListaDuplaMedia::isEmpty() const{
     return head == nullptr;
}

// Retorna o tamanho atual da lista
int ListaDuplaMedia::getLenght() const{
    return this->length;
}

// Remove todos os elementos da lista
void ListaDuplaMedia::clear(){
    while (!isEmpty()) {
        Processos* p = remove(p); 
        delete p; 
    }
}

// Imprime todos os processos da lista
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

// Busca um processo específico na lista
NodeMedia * ListaDuplaMedia::busca(Processos* processo) const{
    NodeMedia * current = this->head;

    // Percorre a lista até encontrar o processo ou chegar ao fim
    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    // Retorna o nó se encontrou o processo, ou nullptr se não encontrou
    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

// Insere um novo processo na lista
Processos* ListaDuplaMedia::insert(Processos* processo){
    // Cria um novo nó
    NodeMedia * newNode = new NodeMedia();
    newNode->processo = processo;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    // Se a lista estiver vazia, o novo nó será tanto head quanto tail
    if(isEmpty()){
        head = tail = newNode;
    }
    else{
        // Adiciona o novo nó no final da lista
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        length++;
        return processo;
    }
}

// Remove o primeiro processo da lista
Processos* ListaDuplaMedia::remove(Processos* processo){
     if (isEmpty()) {
        return nullptr;
    }
    
    NodeMedia* temp = head;
    Processos* processoRemovido = temp->processo;

    // Atualiza o head para o próximo elemento
    head = head->next;
    
    if (head != nullptr) {
        head->previous = nullptr;
    } else {
        // Se a lista ficou vazia, atualiza também o tail
        tail = nullptr;
    }
    
    // Libera a memória do nó removido e atualiza o tamanho
    delete temp;
    length--;
    return processoRemovido;
}
