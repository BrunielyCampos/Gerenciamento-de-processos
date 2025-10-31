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
    
    string assunto;

    int * prtProcessos;
    

    public:
    Processos();

    int IdProcessso (int idProcesso) const;
    int gerarNPT();
    int gerarNPA();
    int Data (int processo) const;
    int Hora (int processo) const;
    void abrirProcesso(int nptProcessos, int npaProcessos); //cria processos 
    int DistribuirPrioridade (TipoProcesso p); //recebe alguma referência do poteiro da pilha.

    //criar metodo para pegar a matricula do solicitante

    void imprimir() const;

};



#endif