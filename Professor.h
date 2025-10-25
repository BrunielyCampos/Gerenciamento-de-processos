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

    vector<Professor> listaProf; 
    string nomeProf;

    public:

    Professor();

    Professor(string nomeProf);
    
    int Especialidade(AtuacaoProfessor especialidade);

    vector<Professor> ListaNomeProf(vector<Professor> listaProf);

    void DefEspecialidade();

    
};
#endif