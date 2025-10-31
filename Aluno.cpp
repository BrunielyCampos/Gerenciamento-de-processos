#include "Aluno.h"
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

    Aluno::Aluno(){  
        DefCurso();
    }

    int Aluno::DefCurso(){

        random_device rd;
        static mt19937 gen(rd());

        uniform_int_distribution<int> distrib(0, static_cast<int>(NomeCurso::A_TPQ));
    
        int opcaoCurso = distrib(gen);
        this->curso = static_cast<NomeCurso>(opcaoCurso); 
        return opcaoCurso;
    }

    vector<string> Aluno::ListNomesAlunos(){
        vector<string> listNomesAlunos = { 
            "Ana Beatriz Ferreira", 
            "Mariana Oliveira", 
            "Pedro Henrique Santos", 
            "Camila Souza", 
            "Joao Victor Lima", 
            "Isabela Rocha", 
            "Rafael Costa", 
            "Larissa Nunes", 
            "Gabriel Martins"
        }; 
        
        random_device rd;
        mt19937 randomEngine(rd());
        uniform_int_distribution<size_t> dist(0, listNomesAlunos.size() - 1);
        size_t idx = dist(randomEngine);

        cout << "Nome: " << listNomesAlunos[idx] << endl;
        return listNomesAlunos;
       
    }

    string Aluno::DefNomeCurso() const {

        switch (this->curso){

        case NomeCurso:: A_INFORMATICA:
           return "Informatica";

        case NomeCurso:: A_QUIMICA:
           return "Quimica";

        case NomeCurso:: A_ADM:
           return "Administracao";

        case NomeCurso:: A_ADMSUB:
           return "Administracao (Subsequente)";

        case NomeCurso:: A_TADS:
           return "Análise e desenvolvimento de sistemas";

        case NomeCurso:: A_TPQ:
           return "Tecnologia em processos Quimicos";
        
        default:
            return "O curso nao faz parte do campus ou nao existe!";
        }
    }

    void Aluno::imprimirAluno(){
        cout << "Nome do aluno: " << nome << endl;
        cout << "Curso: " << DefNomeCurso() << endl;
        cout << "CPF: " << GerarCpf() << endl;
        cout << "Matricula: " << GerarNumMatricula() << endl;
        cout << endl;
    }
