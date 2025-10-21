#include "Professor.h"
#include <iostream>

using namespace std;
    
    Professor::Professor(){
        
    }
    
     int Professor::Especialidade(AtuacaoProfessor especialidade) const{

          
/*        
      int opcao;

        cout << "Escolha a opçao que corresponde a sua especialidade: ";
        cout << "1 - INFORMÁTICA \n";
        cout << "2 - ADMINISTRAÇÃO \n";
        cout << "3 - PROPEDÊUTICA \n";
        cout << "4 - QUÍMICA \n";
        cin >> opcao;

        especialidade = static_cast<AtuacaoProfessor>(opcao); //Casting de int opcao para enum especialidade.*/
     }

    void Professor::imprimir(){
        Pessoa::imprimir();

        cout<< "Especialidede do professor: ";

           if(especialidade == INFORMÁTICA){
                cout<< "Informatica.";
           }
           else if(especialidade == ADMINISTRAÇÃO){
                 cout<< "Administração.";
           }
           
           else if(especialidade == PROPEDÊUTICA){
                cout<< "Propedêutica.";
           }
           
           else if(especialidade == QUÍMICA){
                cout<< "Química.";
           }
           else{
               cout<< "Opção invalida!";
          }
    }