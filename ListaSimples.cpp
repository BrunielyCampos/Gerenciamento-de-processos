#include "ListaSimples.h"
#include <iostream>

// Construtor: Inicializa a lista vazia com início e fim apontando para NULL
ListaSimples::ListaSimples() {
    inicio = NULL;
    fim = NULL;
}

// Destrutor: Remove todos os elementos da lista antes de destruí-la
ListaSimples::~ListaSimples() {
    while (!isEmpty()) {
        delete removerDoInicio();
    }
}

// Insere um novo processo no fim da lista
void ListaSimples::inserirNoFim(Processos* p) {
    // Cria um novo nó com o processo e próximo apontando para NULL
    NoSimples* novoNo = new NoSimples{p, NULL};
    if (isEmpty()) {
        // Se a lista está vazia, início e fim apontam para o novo nó
        inicio = fim = novoNo;
    } else {
        // Senão, conecta o novo nó no fim da lista
        fim->proximo = novoNo;
        fim = novoNo;
    }
}

// Remove e retorna o processo do início da lista
Processos* ListaSimples::removerDoInicio() {
    if (isEmpty()) {
        // Se a lista está vazia, retorna NULL
        return NULL;
    }
    // Guarda referências para o nó a ser removido e seu processo
    NoSimples* noRemovido = inicio;
    Processos* processoRetornado = inicio->processo;
    // Atualiza o início para o próximo nó
    inicio = inicio->proximo;
    if (inicio == NULL) {
        // Se a lista ficou vazia, atualiza o fim para NULL também
        fim = NULL;
    }
    // Libera a memória do nó removido e retorna o processo
    delete noRemovido;
    return processoRetornado;
}

// Verifica se a lista está vazia
bool ListaSimples::isEmpty() const {
    return inicio == NULL;
}
