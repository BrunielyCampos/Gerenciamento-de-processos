#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_

#include <string>
#include "Pessoa.h"

enum AtuacaoProfessor{
    INFORMÁTICA = 1, ADMINISTRAÇÃO, PROPEDÊUTICA, QUÍMICA
};

class Professor : public Pessoa {
    private:

    AtuacaoProfessor especialidade;

    public:

    Professor();
    
    int Especialidade(AtuacaoProfessor especialidade) const;

    void imprimir();

    
};

#endif