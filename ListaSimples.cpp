#include "ListaSimples.h"
#include <iostream>

ListaSimples::ListaSimples() {
    inicio = NULL;
    fim = NULL;
}

ListaSimples::~ListaSimples() {
    while (!isEmpty()) {
        delete removerDoInicio();
    }
}

void ListaSimples::inserirNoFim(Processos* p) {
    NoSimples* novoNo = new NoSimples{p, NULL};
    if (isEmpty()) {
        inicio = fim = novoNo;
    } else {
        fim->proximo = novoNo;
        fim = novoNo;
    }
}

Processos* ListaSimples::removerDoInicio() {
    if (isEmpty()) {
        return NULL;
    }
    NoSimples* noRemovido = inicio;
    Processos* processoRetornado = inicio->processo;
    inicio = inicio->proximo;
    if (inicio == NULL) {
        fim = NULL;
    }
    delete noRemovido;
    return processoRetornado;
}

bool ListaSimples::isEmpty() const {
    return inicio == NULL;
}

/*void ListaSimples::imprimir() const {
    NoSimples* atual = inicio;
    while (atual != NULL) {
        atual->processo->imprimirInformacoesPendentes();
        atual = atual->proximo;
    }
}*/
