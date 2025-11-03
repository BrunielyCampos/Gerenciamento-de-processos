#include "ListaDuplaBaixa.h"
#include "Processos.h"

// Construtor: inicializa lista vazia
ListaDuplaBaixa::ListaDuplaBaixa(){
    this->head = this->tail = nullptr; // sem elementos
    this->length = 0; // tamanho zero
}

// Destrutor: limpa a lista liberando nós
ListaDuplaBaixa::~ListaDuplaBaixa(){
    this->clear();
}

// Retorna true se a lista estiver vazia
bool ListaDuplaBaixa::isEmpty() const{
    return (this->head == nullptr);
}

// Retorna o comprimento atual da lista
int ListaDuplaBaixa::getLenght() const{
    return this->length;
}

// Remove todos os nós da lista e libera memória
void ListaDuplaBaixa::clear(){
    if(!isEmpty()){
        NodeBaixa * current = this->head;
        NodeBaixa * aux;

        // Percorre e deleta cada nó
        while(current != nullptr){
            aux = current;
            current = current->next;
            delete aux;
        }
        // Reinicializa a lista como vazia
        this->head = this->tail = nullptr;
        this->length = 0;
    }
}

// Imprime a lista em ordem crescente (da frente) ou decrescente (de trás)
void ListaDuplaBaixa::print(Ordem1 ordem) const{
    NodeBaixa * current = (ordem == Ordem1::B_PRAFRENTE) ? this->head : this->tail;

    while(current != nullptr){
        cout << "Processo: " << current->processo << " \n";
        // Avança conforme a direção escolhida
        current = (ordem == Ordem1::B_PRAFRENTE) ? current->next : current->previous;
    }
}

// Busca um nó contendo o ponteiro para Processos igual ao fornecido
// Retorna ponteiro const para o nó encontrado ou nullptr se não achar
const NodeBaixa * ListaDuplaBaixa::busca(Processos* processo) const{
    NodeBaixa * current = this->head;

    // Avança enquanto o processo atual for "menor" (assumindo operador < definido)
    while(current != nullptr && current->processo < processo){
        current = current->next;
    }

    // Verifica igualdade (assumindo operador == definido)
    if(current != nullptr && current->processo == processo){
        return current;
    }

    return nullptr;
}

// Insere um novo Processos no final da lista (push back)
// Retorna true em caso de sucesso
bool ListaDuplaBaixa::insert(Processos* processo){

    NodeBaixa * newNode = new NodeBaixa();
    newNode->processo = processo;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    // Se a lista estiver vazia, novo nó é head e tail
    if(isEmpty()){
        head = tail = newNode;
        length++;
        return true;
    }

    // Caso contrário, anexa ao final
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    length++;
    return true;
}

// Remove e retorna o primeiro Processos da lista (pop front)
// Retorna nullptr se a lista estiver vazia
Processos* ListaDuplaBaixa::remove(){
     if (isEmpty()) {
        return nullptr;
    }
    
    NodeBaixa* temp = head;
    Processos* processoRemovido = temp->processo;

    // Atualiza head para o segundo elemento
    head = head->next;
    
    if (head != nullptr) {
        head->previous = nullptr; // novo head não tem anterior
    } else {
        // Lista ficou vazia, atualiza tail
        tail = nullptr;
    }
    
    delete temp; // libera memória do nó removido
    length--;
    return processoRemovido;
}