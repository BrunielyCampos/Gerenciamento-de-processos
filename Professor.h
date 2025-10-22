#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_

#include <string>
#include <random>
#include "Pessoa.h"

enum AtuacaoProfessor{
    INFORMATICA = 1, ADMINISTRACAO, PROPEDEUTICA, QUIMICA
};

class Professor : public Pessoa {
    private:

    AtuacaoProfessor especialidade;

    public:

    Professor();
    
    int Especialidade(AtuacaoProfessor especialidade);

    void DefEspecialidade();

    
};

#endif