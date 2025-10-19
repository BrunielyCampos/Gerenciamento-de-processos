#ifndef _PROCESSOS_H_
#define _PROCESSOS_H_

#include "Pessoa.h"
#include <string>

using namespace std;

enum PrioridadeProcessos{ALTA, MEDIA, BAIXA};

class Processos {
    private:
    int idProcesso;
    int data, hora;
    

    public:
    Processos();

    int IdProcessso (int idProcesso) const;
    int Data () const;
    int Hora () const;
    void abrirProcesso(); //cria processos 
    int DistribuirPrioridade (enum PrioridadeProcessos()); //recebe alguma referência do poteiro da pilha
    int DistribuirProcessos();
    void imprimir() const;

};



#endif