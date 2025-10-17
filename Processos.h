#ifndef _PROCESSOS_H_
#define _PROCESSOS_H_

#include "Pessoa.h"
#include <string>

using namespace std;

class Processos {
    private:
    int idProcesso;
    int pAlta, pMedia, pBaixa;
    int data, hora;
    string assunto;


    public:
    Processos();
    
    Processos(int id, int pA, int pM, int pB, int d, int h, string assunto);

    int getIdProcessso () const;
    int getPAlta () const;
    int getPMedia () const;
    int getPBaixa () const;
    int getData () const;
    int getHora () const;
    string getAssunto () const; //confirmar se precisa de todos os gets

    void abrirProcesso(); //cria processos


    void imprimir() const;

};



#endif