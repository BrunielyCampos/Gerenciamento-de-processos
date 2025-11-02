#ifndef _GERENCIADOR_H_
#define _GERENCIADOR_H_

#include "CaixaDeProcessos.h"

class Gerenciador {
    private:
    int nptProcessos, npaProcessos;
    int namin, namax; //para npa
    int ntmin, ntmax; //para npt
    int n_processos; //para gerar aleatoriamente um número

    CaixaDeProcessos caixa;
    ListaDuplaBaixa listaBaixa;
    ListaDuplaMedia listaMedia;
    ListaSimples listaSimples;

    double pA, pB, pM;

    public:
    Gerenciador();
    Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados);
    
    void iniciarDia(int dias = 3);

    int gerarNPT();
    int gerarNPA();
    int gerarN_Processos();
    double gerarProbabilidade();
    void abrirProcesso(int nptProcessos, int npaProcessos);
    void tramitarProcesso();
    int distribuirPrioridade(TipoProcesso p);
    Pessoa* CriarSolicitanteAleatorio();
    void imprimir() const; //imprimir processos pendentes
};

#endif