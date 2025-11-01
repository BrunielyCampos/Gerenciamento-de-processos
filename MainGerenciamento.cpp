#include <iostream>
#include <ctime>
#include <random>
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"

using namespace std;


int main(){
    // system("cls");

    Aluno * aluno = new Aluno();
    Professor * professor = new Professor();
    
    srand(time(0));

    int tipoUser = rand() % 2 + 1;  // Gera apenas 1 ou 2

        if(tipoUser == 1){
            aluno->imprimirAluno();
        }

        else if(tipoUser == 2){
            professor->ImprimirProfessor();
        }
        
}