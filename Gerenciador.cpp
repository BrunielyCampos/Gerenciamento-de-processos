#include "Gerenciador.h"
#include "Processos.h"
#include "ListaSimples.h"
#include "ListaDuplaBaixa.h"
#include "ListaDuplaMedia.h"
#include "CaixaDeProcessos.h"
#include "Aluno.h"
#include "Professor.h"
#include "Pessoa.h"

#include <iostream>
#include <random>

Gerenciador::Gerenciador(){
    namin = 1;
    namax = 5;
    ntmin = 3;
    ntmax = 10;
}

Gerenciador::Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados){
    namin = minAbertos;
    namax = maxAbertos;
    ntmin = minTramitados;
    ntmax = maxTramitados;
}

 int Gerenciador::gerarNPT(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 10);

        int npt = distrib(gen);
        this->nptProcessos = npt;
        return npt;
    }

    int Gerenciador::gerarNPA(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(1, 5);

        int npaGerado = distrib(gen);
        this->npaProcessos = npaGerado;
        return npaGerado;
    }

    Pessoa* Gerenciador::CriarSolicitanteAleatorio() {
    
        mt19937 engine;
        uniform_int_distribution<int> dist(0, 1);
        bool isAluno = (dist(engine) == 0);

        Aluno * aluno = new Aluno();
        Professor * professor = new Professor();

        if (isAluno) {  
        aluno->imprimirAluno();
            
        } 
        else {
            professor->ImprimirProfessor();   
        }
}

    double Gerenciador::gerarProbabilidade(){
        
    }


    int Gerenciador::distribuirPrioridade (TipoProcesso p){
        
       
    }

    void Gerenciador::tramitarProcesso(){
        
    }

    int Gerenciador::gerarN_Processos(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 15); //processos entre 3 e 15

        int n_processosGerado = distrib(gen);
        this->n_processos = n_processosGerado;
        return n_processosGerado;
    }


    void Gerenciador::abrirProcesso(int nptProcessos, int npaProcessos){ //criar processos
    cout << "Recebendo Processos..." << "\n";

        Processos * processos = new Processos();
        CaixaDeProcessos * caixa = new CaixaDeProcessos();
        
        for(int i = 0; i < n_processos; i++){

            Pessoa* solicitante = this->CriarSolicitanteAleatorio();

            int id = processos->IdProcesso();
            string data = processos->GerarDataAleatoria();
            string hora = processos->gerarHoraAleatoria();

            //Enviar para pilha AQUI
            
            string assuntos[] = { //falta mais
            "Requerimento de Documentos",
            "Revisão de Nota",
            "Solicitação de Declaração",
            "Pedido de Transferência",
            "Solicitação de suporte tecnicos de TI", "Revisão de Nota",
            "Solicitação de Laboratório", 
            "Apresentar Justificativa de faltas",  "Requerimento de apresentação de Trabalho de conclusão de curso", 
            "Requerimento de apresentação de Relatório de Pratica Profissional",
            "Requerimento para Trancamento de Curso", "Solicitação de Readimição"
            };
        }
        cout << "Processos recebidos com sucesso!" << "\n" << "Exibindo:" << "\n";
            //for para exibir os processos criados e seus atributos

        // Processos* novoProcesso = new Processos(
        //     id,
        //    data,
        //    hora, // Passa o solicitante que acabamos de criar
        //     assunto,
        //     dataHoraCompleta
        // );

        //  caixa->empilhar(novoProcesso);

    
    }

    void iniciarDia(){
    for(int dia = 0; dia < 3; dia++){
        
        for(int i = 0; i < 3; i++){
            //Gerenciador::abrirProcessos();
        }

        for(int tarde = 0; tarde < 3; tarde++){
            //Gerenciador::tramitarProcessos();
        }

        //Gerenciador::exibirProcesos();
    }
}