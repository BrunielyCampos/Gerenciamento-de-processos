    #include "Aluno.h"
    #include <iostream>

    Aluno::Aluno(){
        Pessoa::Nome("Não definido");
        Pessoa::Cpf("Não definido");
    }
    
    Aluno::Aluno (){


    }
    
    // string Aluno::getCurso() const{

    // }

    void Aluno::setCurso (NomeCurso curso){
        
        int opcao;

        cout << "\nEscolha o curso do aluno:\n";
        cout << "1 - Informática\n";
        cout << "2 - Química\n";
        cout << "3 - Administração\n";
        cout << "4 - Administração Subsequente\n";
        cout << "5 - TADS\n";
        cout << "6 - TPQ\n";
        cout << "Digite o número correspondente: ";
        cin >> opcao;

        // Converte número → enum
        curso = static_cast<NomeCurso>(opcao);
        
    }

    void Aluno::imprimir(){
        Pessoa::imprimir();

        cout << "Curso do Aluno: ";
    try{
         if(curso == INFORMATICA){
             cout << "Informatica\n";
        }
        else if(curso == QUIMICA){
             cout << "Quimica\n";
        }
        else if(curso == ADM){
             cout << "ADM\n";
        }
        else if(curso == ADMSUB){
             cout << "ADMSUB\n";
        }
        else if(curso == TADS){
             cout << "Análise e Desenvolvimento de Sistemas\n";
        }
        else if(curso == TPQ){
             cout << "TPQ\n";
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
       
       

    }