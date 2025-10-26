#ifndef _PROCESSOS_H_
#define _PROCESSOS_H_
#include "CaixaDeProcessos.h"

#include "Pessoa.h"
#include <string>

using namespace std;

enum PrioridadeProcessos{ALTA, MEDIA, BAIXA};

class Processos {
    private:
    int idProcesso;
    int data, hora;
    
    string assunto;

    int * prtProcessos;
    

    public:
    Processos();

    int IdProcessso (int idProcesso) const;
    int Data () const;
    int Hora () const;
    void abrirProcesso(); //cria processos 
    int DistribuirPrioridade (TipoProcesso p); //recebe alguma referência do poteiro da pilha.

    //criar metodo para pegar a matricula do solicitante

    void abrirProcesso(); //cria processos

    void imprimir() const;

};



#endif