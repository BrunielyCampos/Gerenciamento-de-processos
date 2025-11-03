#ifndef _CAIXA_PROCESSOS_  // Guarda de inclusão para evitar inclusões múltiplas
#define _CAIXA_PROCESSOS_
#include "Processos.h"     // Inclui o arquivo de cabeçalho Processos.h

// Estrutura do nó para a pilha de processos
struct Node{
    Processos * processo;  // Ponteiro para um objeto do tipo Processos
    Node *proximo;        // Ponteiro para o próximo nó na pilha
};

// Classe que implementa uma pilha de processos
class CaixaDeProcessos {
    private:
        Node *top;        // Ponteiro para o topo da pilha

    public:
        // Construtor da classe
        CaixaDeProcessos();

        // Método para adicionar um novo processo no topo da pilha
        void empilhar(Processos* novoProcesso);

        // Método para remover e retornar o processo do topo da pilha
        Processos* Desempilhar();

        // Método para verificar se a pilha está vazia
        bool isEmpty();
};
#endif