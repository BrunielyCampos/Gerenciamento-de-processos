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
    int m_data;
    
    string assunto;

    int * prtProcessos;
    

    public:

    Processos();
    int idProcesso (int idProcesso) const;
    int data (int processo) const;
    int hora (int processo) const;
    void abrirProcesso(int nptProcessos, int npaProcessos); //cria processos 

    void imprimir() const;

};

#endif