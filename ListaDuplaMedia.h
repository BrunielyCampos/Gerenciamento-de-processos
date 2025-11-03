#ifndef _LISTADUPLAMEDIA_H_  // Guarda de inclusão para evitar múltiplas inclusões do arquivo
#define _LISTADUPLAMEDIA_H_

#include "Processos.h"  // Inclui o arquivo de cabeçalho dos processos
#include <iostream>

using std::cout;  // Usando cout do namespace std

// Estrutura do nó para a lista duplamente encadeada
struct NodeMedia{
    NodeMedia * next;     // Ponteiro para o próximo nó
    Processos* processo;  // Ponteiro para o processo armazenado
    NodeMedia * previous; // Ponteiro para o nó anterior
};

// Enumeração para definir a direção da navegação na lista
enum Ordem2{
    M_PRAFRENTE,  // Para frente
    M_PRATRAS     // Para trás
};

// Classe que implementa uma lista duplamente encadeada
class ListaDuplaMedia {
    private:
    NodeMedia * head;   // Ponteiro para o início da lista
    NodeMedia * tail;   // Ponteiro para o fim da lista
    int length;         // Tamanho atual da lista

    public:
    ListaDuplaMedia(); // Construtor
    ~ListaDuplaMedia(); // Destrutor

    bool isEmpty() const;    // Verifica se a lista está vazia
    int getLenght() const;  // Retorna o tamanho da lista
    
    void clear();  // Limpa a lista

    NodeMedia * busca(Processos* processo) const;  // Busca um processo na lista
    Processos* insert(Processos* processo);        // Insere um processo na lista
    Processos* remove(Processos* processo);        // Remove um processo da lista
    void print() const;                           // Imprime a lista
};

#endif