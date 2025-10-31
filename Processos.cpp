#include "Processos.h"
#include "CaixaDeProcessos.h"
#include <random>

    int Processos::DistribuirPrioridade (TipoProcesso elemento){
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

    int Processos::gerarNPT(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 10);

        int nptGerado = distrib(gen);
        this->nptProcessos = nptGerado;
        return nptGerado;
    }

    int Processos::gerarNPA(){
        
    }

    void Processos::abrirProcesso(int nptProcessos, int npaProcessos){
        
    }
    
    int Processos::IdProcessso (int idProcesso) const{
        
    }
   
    int Processos::Data (int processo) const{

    }

    int Processos::Hora (int processo) const{

    }

   


    void Processos::imprimir() const{

    }