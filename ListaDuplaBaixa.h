#ifndef _LISTADPULABAIXA_H_  // Guarda de inclusão para evitar inclusões múltiplas
#define _LISTADUPLABAIXA_H_

#include "Processos.h"  // Inclui o arquivo de cabeçalho dos processos
#include <iostream>

using std::cout;  // Usando cout do namespace std

// Estrutura do nó para a lista duplamente encadeada de baixa prioridade
struct NodeBaixa{
    NodeBaixa * next;      // Ponteiro para o próximo nó
    Processos* processo;    // Ponteiro para o processo
    NodeBaixa * previous;   // Ponteiro para o nó anterior
};

// Enumeração para definir a ordem de impressão
enum Ordem1{
    B_PRAFRENTE,  // Para frente
    B_PRATRAS     // Para trás
};

// Classe que implementa uma lista duplamente encadeada para processos de baixa prioridade
class ListaDuplaBaixa {
    private:
    NodeBaixa * head;   // Ponteiro para o início da lista
    NodeBaixa * tail;   // Ponteiro para o fim da lista
    int length;         // Tamanho da lista

    public:
    ListaDuplaBaixa();  // Construtor
    ~ListaDuplaBaixa(); // Destrutor

    bool isEmpty() const;             // Verifica se a lista está vazia
    int getLenght() const;           // Retorna o tamanho da lista

    void clear();                     // Limpa a lista
    void print(Ordem1 ordem = Ordem1::B_PRAFRENTE) const;  // Imprime a lista na ordem especificada

    const NodeBaixa * busca(Processos* processo) const;  // Busca um processo na lista
    bool insert(Processos* processo);                    // Insere um processo na lista
    Processos* remove();                                 // Remove um processo da lista

};

#endif