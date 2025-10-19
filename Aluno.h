#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_

#include "Pessoa.h"

enum NomeCurso{
    INFORMATICA, QUIMICA, ADM, ADMSUB, TADS, TPQ
};

class Aluno : public Pessoa {
    private:
    string curso;

    public:

    Aluno();
    
    Aluno (string curso);
    
    string getCurso() const;

    void setCurso (string curso);

   
};
#endif