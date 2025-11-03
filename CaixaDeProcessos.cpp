#include <iostream>
#include "CaixaDeProcessos.h"

using std::cout;

// Construtor padrão da pilha de processos.
// Inicializa a caixa (pilha). Se 'top' for membro da classe, espera-se que seja inicializado
// no construtor da definição da classe (ou já inicializado no header).
CaixaDeProcessos::CaixaDeProcessos(){
    
}

// Empilha um novo processo na pilha (push).
// Recebe um ponteiro para um Processos e cria um novo Node que passa a ser o topo.
void CaixaDeProcessos::empilhar( Processos *  novoProcesso){

    Node * novo = new Node; // cria um novo nó (container) para armazenar o processo
    novo->processo = novoProcesso; // armazena o ponteiro para o processo dentro do nó
    novo->proximo = top; // faz o novo nó apontar para o nó que antes estava no topo
    top = novo; // atualiza o topo para o novo nó

    // Observação: empilhar cria um novo nó e o coloca no início da lista (pilha LIFO).
}

 // Desempilha e retorna o processo do topo (pop).
 // Retorna nullptr e imprime mensagem se a pilha estiver vazia.
 Processos*  CaixaDeProcessos::Desempilhar(){
    if (isEmpty()){               
        cout<< "A Caixa de processos está VAZIA!"; // aviso se não há elementos
        return nullptr;
    }

    Node * temp = top; // guarda o nó do topo em um ponteiro temporário
    Processos * elemento = temp->processo; // obtém o ponteiro para o processo guardado
    top = temp->proximo; // atualiza o topo para o próximo nó na pilha
    delete temp; // libera a memória do nó removido (mas não do processo apontado)

    return elemento; // retorna o processo que estava no topo
 }

 // Verifica se a pilha está vazia (top == nullptr).
 bool CaixaDeProcessos::isEmpty(){
    return top == nullptr;
 }
