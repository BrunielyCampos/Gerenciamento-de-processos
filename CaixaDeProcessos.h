#ifndef _CAIXA_PROCESSOS_
#define _CAIXA_PROCESSOS_
#include "Processos.h"

struct Node{

    Processos * processo;
    Node *proximo;
            
};

class CaixaDeProcessos {
    private:

       Node *top;

    public:

    CaixaDeProcessos();

    void empilhar( Processos* novoProcesso);
    Processos* Desempilhar();
    bool isEmpty();
};
#endif