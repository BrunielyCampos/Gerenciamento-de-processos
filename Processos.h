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
    int nptProcessos, npaProcessos;
    int namin, namax; //para npa
    int ntmin, ntmax; //para npt
    
    string assunto;

    int * prtProcessos;
    

    public:

    int idProcesso (int idProcesso) const;
    int gerarNPT();
    int gerarNPA();
    int data (int processo) const;
    int hora (int processo) const;
    void abrirProcesso(int nptProcessos, int npaProcessos); //cria processos 
    void tramitarProcesso(); //passa o processo para o próximo setor
    int distribuirPrioridade (TipoProcesso p); //recebe alguma referência do poteiro da pilha.

    //criar metodo para pegar a matricula do solicitante

    void imprimir() const;

};



#endif