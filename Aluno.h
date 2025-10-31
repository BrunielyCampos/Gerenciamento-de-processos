#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_


#include "Pessoa.h"
#include <vector>
#include <string>

using namespace std;

enum NomeCurso {
    A_INFORMATICA, A_QUIMICA, A_ADM, A_ADMSUB, A_TADS, A_TPQ
};

class Aluno : public Pessoa {
    private:
        NomeCurso curso;           
        string nome;         
        
    public:
        Aluno();
        vector<std::string> ListNomesAlunos();  // Adicionado std::
        string DefNomeCurso() const;            // Adicionado std::
        int DefCurso();
        void imprimirAluno();
};

#endif