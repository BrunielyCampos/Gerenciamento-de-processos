#ifndef _CAIXA_PROCESSOS_
#define _CAIXA_PROCESSOS_

typedef int TipoProcesso;

struct Node{

    int processo;
    Node *proximo;
            
};

class CaixaDeProcessos {
    public:

       Node *top;

    private:

    CaixaDeProcessos();

    void empilhar(TipoProcesso novoProcesso);
    void Desempilhar(void (*DistribuirPrioridade)(TipoProcesso));
    bool isEmpty();
};
#endif