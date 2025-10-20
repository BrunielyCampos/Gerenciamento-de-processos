#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_

#include "Pessoa.h"

using std::cout;
using std::cin;

enum NomeCurso{
    INFORMATICA = 1, QUIMICA, ADM, ADMSUB, TADS, TPQ
};

class Aluno : public Pessoa {
    private:
        NomeCurso curso;

    public:
    
    Aluno ();

    void setCurso (NomeCurso curso);

    void imprimir();

   
};
#endif