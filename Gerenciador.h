#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include "CaixaDeProcessos.h"
#include "ListaSimples.h"
#include "ListaDuplaMedia.h"
#include "ListaDuplaBaixa.h"
#include "Processos.h"
#include "Pessoa.h"

class Gerenciador {
public:


    Gerenciador(); 
    Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados); 

    void iniciarSimulacao(int dias);

private:

    CaixaDeProcessos caixaDeProcessos;
    ListaSimples listaAlta;
    ListaDuplaMedia listaMedia;
    ListaDuplaBaixa listaBaixa;
    int namin, namax, ntmin, ntmax;

    void executarUmDia();

    void abrirNovosProcessos();

    void organizarProcessos();

    void tramitarProcessos();

    void imprimirPendentes() const;

    int gerarNPA();

    int gerarNPT();
    
    PrioridadeProcessos sortearPrioridadeAleatoria();

    void distribuirPrioridade(Processos* processo);
    
    Pessoa* criarSolicitanteAleatorio();
};

#endif