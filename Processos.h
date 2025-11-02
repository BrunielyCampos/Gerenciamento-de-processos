#ifndef _PROCESSOS_H_
#define _PROCESSOS_H_
#include "CaixaDeProcessos.h"

#include "Pessoa.h"
#include <string>

using namespace std;

class Processos {
    private:
    int idProcesso;
    int data, hora;
    
    
    string assunto;

    mt19937 engine;
    

    public:

    Processos();
    int gerarN_Processos();
    int IdProcesso ();
    string GerarDataAleatoria ();
    string gerarHoraAleatoria();
    
    void imprimir() const;

};

#endif