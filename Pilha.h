#ifndef _PILHA_H_
#define _PILHA_H_

class Pilha {
    public:

    int * ptrInicio;
    int capacidadePilha;
    int topoPilha;

    private:
    Pilha();

    void empilhar();
    void desempilhar();
    void vazia();
    void exibir();
};

#endif