#ifndef _PROCESSOS_H_
#define _PROCESSOS_H_

#include <string>

using namespace std;

enum PrioridadeProcessos{ALTA, MEDIA, BAIXA};

class Processos {
    private:

    int idGerado;
    string dataAbertura;
    string horaAbertura;
    
    
    PrioridadeProcessos prioridade;
    
    string assunto;

    
    
    int gerarIdUnico();
    string GerarDataAleatoria();
    string GerarHoraAleatoria();

    public:

    Processos();
    int gerarN_Processos();
    int IdProcesso ();
    void setPrioridade(PrioridadeProcessos p);
    PrioridadeProcessos getPrioridade();
    void imprimir();

};

#endif