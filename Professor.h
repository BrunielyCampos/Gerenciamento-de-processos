#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_

#include <string>
#include "Pessoa.h"

using namespace std;

enum AtuacaoProfessor{
    P_INFORMATICA, P_ADMINISTRACAO, P_PROPEDEUTICA, P_QUIMICA
};

class Professor : public Pessoa {
    private:
        AtuacaoProfessor especialidade;  

    public:
        Professor();

        int Especialidade();

        // agora retorna um único nome (string), não um vetor
        string ListaNomeProf();

        string DefEspecialidade();

        void ImprimirProfessor();
};
#endif