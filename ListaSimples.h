#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

#include "Processos.h"

struct NoSimples {
    Processos* processo;
    NoSimples* proximo;
};

class ListaSimples {
private:
    NoSimples* inicio;
    NoSimples* fim;

public:
    ListaSimples();
    ~ListaSimples();

    void inserirNoFim(Processos* p);
    Processos* removerDoInicio();
    bool isEmpty() const;
    void imprimir() const;
};

#endif // LISTA_SIMPLES_H