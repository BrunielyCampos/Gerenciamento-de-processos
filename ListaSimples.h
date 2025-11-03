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

    void inserirNoFim(Processos* processo);
    Processos* removerDoInicio();
    bool isEmpty() const;
};

#endif