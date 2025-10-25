    #include "Aluno.h"
    #include <iostream>
    #include<random>

    using namespace std;

    Aluno::Aluno(){  
        DefCurso();
    }

    Aluno::Aluno(string nome){
        this->nome;
    }

    int Aluno::DefCurso(){

        random_device rd;
        static mt19937 gen(rd());

        uniform_int_distribution<int> distrib(1, static_cast<int>(NomeCurso::TPQ));
    
        int opcaoCurso = distrib(gen);

        this->curso = static_cast<NomeCurso>(opcaoCurso); 
  
        return opcaoCurso;

    }

    vector<Aluno> ListNomesAlunos(vector<Aluno> ListNomesAlunos){
          
        ListNomesAlunos.push_back(Aluno{"Ana Beatriz Ferreira"});
        ListNomesAlunos.push_back(Aluno{"Mariana Oliveira"});
        ListNomesAlunos.push_back(Aluno{"Pedro Henrique Santos"});
        ListNomesAlunos.push_back(Aluno{"Camila Souza"});
        ListNomesAlunos.push_back(Aluno{"João Victor Lima"});
        ListNomesAlunos.push_back(Aluno{"Isabela Rocha"});
        ListNomesAlunos.push_back(Aluno{"Rafael Costa"});
        ListNomesAlunos.push_back(Aluno{"Larissa NunegetNomeAluno"});
        ListNomesAlunos.push_back(Aluno{"Gabriel Martins"});
    }

    string Aluno::getNomeCurso() const {

        switch (this->curso){

        case NomeCurso::INFORMATICA:
           cout << "Informatica";
        break;

        case NomeCurso::QUIMICA:
           cout << "Quimica";
        break;

        case NomeCurso::ADM:
           cout << "Administração.";
        break;

        case NomeCurso::ADMSUB:
           cout << "Adminidtração (Subsequente)";
        break;

        case NomeCurso::TADS:
           cout << "Análise e desenvolvimento de sistemas";
        break;

        case NomeCurso::TPQ:
           cout << "Tecnologia em processos Quimicos";
        break;
        
        default:
            cout<<"O curso não faz parte do campus ou não existe!";
            
            break;
        }
    }