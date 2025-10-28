#include "Processos.h"
#include "CaixaDeProcessos.h"

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

    void Processos::abrirProcesso(){ //cria processos

    }
    
    int Processos::IdProcessso (int idProcesso) const{
        
    }
   
    int Processos::Data () const{

    }

    int Processos::Hora () const{

    }

   


    void Processos::imprimir() const{

    }