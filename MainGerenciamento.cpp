#include <iostream>
#include <ctime>
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
//#include "Processos.h"

using namespace std;

int main(){
    system("cls");

    Aluno * aluno = new Aluno();
    Professor * professor = new Professor();
    
    srand(time(0));

    int tipoUser = rand() % 3;


        if(tipoUser == 1){
            aluno->imprimirAluno();
        }

        else if(tipoUser == 2){
            professor->Imprimir();
        }

    
}
