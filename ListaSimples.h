#ifndef LISTA_SIMPLES_H    // Guarda de inclusão para evitar múltiplas definições
#define LISTA_SIMPLES_H

#include "Processos.h"     // Inclui o arquivo de cabeçalho Processos.h

// Estrutura do nó para a lista simplesmente encadeada
struct NoSimples {
    Processos* processo;   // Ponteiro para um objeto do tipo Processos
    NoSimples* proximo;    // Ponteiro para o próximo nó da lista
};

// Classe que implementa uma lista simplesmente encadeada
class ListaSimples {
private:
    NoSimples* inicio;     // Ponteiro para o primeiro nó da lista
    NoSimples* fim;        // Ponteiro para o último nó da lista

public:
    ListaSimples();        // Construtor da classe
    ~ListaSimples();       // Destrutor da classe

    // Métodos da lista
    void inserirNoFim(Processos* processo);    // Insere um processo no fim da lista
    Processos* removerDoInicio();              // Remove e retorna o processo do início da lista
    bool isEmpty() const;                       // Verifica se a lista está vazia
};

#endif