#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_

#include "Pessoa.h"
#include <vector>

// using std::cout;
// using std::cin;

enum NomeCurso{
    INFORMATICA = 1, QUIMICA, ADM, ADMSUB, TADS, TPQ
};

class Aluno : public Pessoa {
    private:
        enum NomeCurso curso;
        vector<Aluno> ListNomesAlunos; 
        string nome;
        

    public:
    
    Aluno();
    Aluno(string nome);

    string getNomeCurso() const;

    vector<Aluno> ListNomesAlunos(vector<Aluno> ListNomesAlunos);


    int DefCurso ();

    void imprimir();

   
};
#endif