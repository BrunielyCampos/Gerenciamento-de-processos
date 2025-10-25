#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;
    
     Professor::Professor(){
          
     }
    
     Professor::Professor(string nomeProf){
          this->nomeProf;
     }
    
     int Professor::Especialidade(AtuacaoProfessor especialidade){
          random_device rd;
          static mt19937 gen(rd());
          
         

          uniform_int_distribution<int> distrib(1, static_cast<int>(AtuacaoProfessor::QUIMICA));

          int opcaoProf = distrib(gen);

          this->especialidade = static_cast<AtuacaoProfessor>(opcaoProf);
          
          return opcaoProf;
     } //Em um laço for, a partir de um radom pegando as posiçoes do vetor, iremos atribuir um aluno a um processo, contendo os numéros de mátriculas e cpf gerandos alatóriamente "Montando um professor".

     vector<Professor> ListaNomeProf(vector<Professor> listaProf);

     void Professor::DefEspecialidade(){

        cout<< "Especialidede do professor: ";

          
        switch (this->especialidade){
        case AtuacaoProfessor::INFORMATICA:
           cout<< "Informatica.";
        break;
        case AtuacaoProfessor::ADMINISTRACAO:
           cout<< "Administração.";
        break;
        case AtuacaoProfessor::PROPEDEUTICA:
           cout<< "Propedeutica.";
        break;
        case AtuacaoProfessor::QUIMICA:
           cout<< "Quimica.";
        break;
        default:
          cout<<"Atuação invalida, não está presente no campus ou não existe!";
          break;
        }
    }