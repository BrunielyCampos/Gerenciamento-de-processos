#include <iostream>
#include <ctime>
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
#include "Processos.h"

using namespace std;

int main(){
    
    srand(time(0));

    int tipoUser = 1 + rand() % 2;

    Professor * listaProf[10]; // Array de professores com tamanho 10
    Aluno * listNomeAlunos[10]; // Array de professores com tamanho 10
    
    //For para "Montar o Professor"

    if(tipoUser == 1){
      for (int i = 0; i < sizeof(listaProf)/sizeof(Professor*); i++){
            listaProf[i]= new Professor;
            listaProf[i]->ListaNomeProf();
            listaProf[i]->GerarCpf();
            listaProf[i]->GerarNumMatricula();
            listaProf[i]->DefEspecialidade();
      }  
    }

    else if(tipoUser == 2){
        for (int i = 0; i < sizeof(listNomeAlunos)/sizeof(Aluno); i++){   
            listNomeAlunos[i] = new Aluno;
            listNomeAlunos[i]->ListaNomeAlunos();
            listNomeAlunos[i]->DefCurso();   
            listNomeAlunos[i]->GerarCpf();
            listNomeAlunos[i]->GerarNumMatricula();
            listNomeAlunos[i]->getNomeCurso();
        }
    }

    
}
