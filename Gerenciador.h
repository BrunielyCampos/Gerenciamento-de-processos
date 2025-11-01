#ifndef _GERENCIADOR_H_
#define _GERENCIADOR_H_

#include "CaixaDeProcessos.h"

class Gerenciador {
    private:
    int nptProcessos, npaProcessos;
    int namin, namax; //para npa
    int ntmin, ntmax; //para npt

    CaixaDeProcessos caixa;
    ListaDuplaBaixa listaBaixa;
    ListaDuplaMedia listaMedia;
    ListaSimples listaSimples;

    double pA, pB, pM;

    public:
    Gerenciador();
    Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados);
    
    int gerarNPT();
    int gerarNPA();
    double gerarProbabilidade();
    void abrirProcessos();
    void tramitarProcesso();
    int distribuirPrioridade(TipoProcesso p);

    void imprimir() const; //imprimir processos pendentes
};

#endif