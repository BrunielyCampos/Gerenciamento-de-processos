#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_


#include "Pessoa.h"
#include <vector>

using namespace std;

enum NomeCurso{
    INFORMATICA = 1, QUIMICA, ADM, ADMSUB, TADS, TPQ
};

class Aluno : public Pessoa {
    private:
    
    enum NomeCurso curso;
    vector<Aluno> ListNomesAlunos; 
    string nome;
        
    public:
    
    Aluno ();
    Aluno();
    Aluno(string nome);

    vector<Aluno> ListNomesAlunos(vector<Aluno> ListNomesAlunos);

    string getNomeCurso() const;

    int DefCurso ();
};
#endif