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

   mt19937 engine;
    

    public:

    Processos();
    int idProcesso (int idProcesso) const;
    string GerarDataAleatoria ();
    string gerarHoraAleatoria();
    void abrirProcesso(int nptProcessos, int npaProcessos); //cria processos 

    void imprimir() const;

};

#endif