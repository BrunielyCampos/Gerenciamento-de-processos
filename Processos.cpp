#include "Processos.h"
#include "CaixaDeProcessos.h"
#include <random>

    int Processos::idProcesso (int idProcesso) const{
        
    }
   
    int Processos::data (int processo) const{

    }

    int Processos::gerarNPT(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 10);

        int nptGerado = distrib(gen);
        this->nptProcessos = nptGerado;
        return nptGerado;
    }

    int Processos::gerarNPA(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(1, 5);
    }

    int Processos::hora (int processo) const{

    }

    void Processos::abrirProcesso(int nptProcessos, int npaProcessos){
        
    }

    void Processos::tramitarProcesso(){
        
    }

    int Processos::distribuirPrioridade (TipoProcesso elemento){
        // Use the passed-in priority 'p' instead of an undefined 'elemento'
        if (elemento == ALTA) {
            //AlgumNome = PtrEstruturaDupla1
            return ALTA;
        }
        else if (elemento == MEDIA) {
            //AlgumNome = PtrEstruturaDupla2
            return MEDIA;
        }
        else if (elemento == BAIXA) {
            //AlgumNome = PtrEstruturaSimples3
            return BAIXA;
        }
        return elemento;
    } //recebe alguma referência do poteiro da pilha


    void Processos::imprimir() const{

    }