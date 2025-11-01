#include "Gerenciador.h"
#include "Processos.h"
#include "ListaSimples.h"
#include "ListaDuplaBaixa.h"
#include "ListaDuplaMedia.h"
#include "CaixaDeProcessos.h"

#include <iostream>
#include <random>

Gerenciador::Gerenciador(){
    namin = 1;
    namax = 5;
    ntmin = 3;
    ntmax = 10;
}

Gerenciador::Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados){
    namin = minAbertos;
    namax = maxAbertos;
    ntmin = minTramitados;
    ntmax = maxTramitados;
}

 int Gerenciador::gerarNPT(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 10);

        int nptGerado = distrib(gen);
        this->nptProcessos = nptGerado;
        return nptGerado;
    }

    int Gerenciador::gerarNPA(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(1, 5);

        int npaGerado = distrib(gen);
        this->npaProcessos = npaGerado;
        return npaGerado;
    }

    double Gerenciador::gerarProbabilidade(){
        
    }


    int Gerenciador::distribuirPrioridade (TipoProcesso p){
        // Use the passed-in priority 'p' instead of an undefined 'elemento'
    //     if (elemento == ALTA) {
    //         //AlgumNome = PtrEstruturaDupla1
    //         return ALTA;
    //     }
    //     else if (elemento == MEDIA) {
    //         //AlgumNome = PtrEstruturaDupla2
    //         return MEDIA;
    //     }
    //     else if (elemento == BAIXA) {
    //         //AlgumNome = PtrEstruturaSimples3
    //         return BAIXA;
    //     }
    //     return elemento;
     }

    void Gerenciador::tramitarProcesso(){
        
    }