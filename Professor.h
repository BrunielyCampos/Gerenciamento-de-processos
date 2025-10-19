#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_

#include <string>
#include "Pessoa.h"

enum AtuacaoProfessor{
    INFORMÁTICA, ADMINISTRAÇÃO, PROPEDÊUTICA, QUÍMICA
};

class Professor : public Pessoa {
    private:

       enum AtuacaoProfessor especialidade;

    public:

    Professor();
    
    int Especialidade(AtuacaoProfessor especialidade) const;

    void setEspecialidade(string especialidade);

    
};

#endif