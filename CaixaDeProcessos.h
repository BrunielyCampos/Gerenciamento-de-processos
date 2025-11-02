#ifndef _CAIXA_PROCESSOS_
#define _CAIXA_PROCESSOS_

typedef int TipoProcesso;

struct Node{

    int processo;
    Node *proximo;
            
};

class CaixaDeProcessos {
    private:

       Node *top;

    public:

    CaixaDeProcessos();

    void empilhar(TipoProcesso novoProcesso);
    TipoProcesso Desempilhar(void (*DistribuirPrioridade)(TipoProcesso));
    bool isEmpty();
};
#endif