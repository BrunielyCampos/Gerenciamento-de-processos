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

using namespace std;

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



   Pessoa* Gerenciador::CriarSolicitanteAleatorio(){
    
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


   PrioridadeProcessos Gerenciador::GerarProbabilidade() {
    
    random_device rd;
    uniform_int_distribution<int> distrib(0, 99);
    static mt19937 gen(rd());
    int sorteio = distrib(gen);

    if (sorteio < 10) { 
        return  PrioridadeProcessos::ALTA;
    }
   
    else if (sorteio < 40) { // 30% de chance
        return  PrioridadeProcessos::MEDIA;
    }
   
    else { // 60% de chance
        return  PrioridadeProcessos::BAIXA;
    }
}

    int Gerenciador::GerarPrioridade(){

        PrioridadeProcessos p = Processo->getPrioridade();

    // Passo 2: "Entregue no endereço correto" (coloque na lista certa).
    switch (p) {
        case PrioridadeProcessos::ALTA:
            this->listaAlta.inserirNoFim(processo);
            std::cout << "-> Processo ID " << processo->IdProcesso() << " distribuido para: ALTA PRIORIDADE\n";
            break;

        case PrioridadeProcessos::MEDIA:
            this->listaMedia.insert(processo); // Lembre-se de corrigir o 'insert' para aceitar Processos*
            std::cout << "-> Processo ID " << processo->IdProcesso() << " distribuido para: MEDIA PRIORIDADE\n";
            break;

        case PrioridadeProcessos::BAIXA:
            this->listaBaixa.insert(processo); // Lembre-se de corrigir o 'insert' para aceitar Processos*
            std::cout << "-> Processo ID " << processo->IdProcesso() << " distribuido para: BAIXA PRIORIDADE\n";
            break;
    }
    }

    void Gerenciador::DistribuirPrioridade(Processos* processo){
            static int counter = 0;
            counter++;

            int mod = counter % 10;

            if (mod == 0) 
            return PrioridadeProcessos::ALTA;           // 10%
            else if (mod >= 1 && mod <= 3) 
            return PrioridadeProcessos::MEDIA; // 30%
            else 
            return PrioridadeProcessos::BAIXA;                   // 60%
        
       
    }


    void Gerenciador::tramitarProcessos(){
        if(Prioridade == 1){
            //vai pra pilha
        }
    }

    int Gerenciador::gerarN_Processos(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 15); //processos entre 3 e 15

        int n_processosGerado = distrib(gen);
        int npaProcessos = n_processosGerado;
        return npaProcessos;
    }

    void Gerenciador::abrirProcesso(int nptProcessos, int npaProcessos){ //criar processos
    cout << "Recebendo Processos..." << "\n";

        Processos * processos = new Processos();
        
        for(int i = 0; i < npaProcessos; i++){

            Pessoa* solicitante = this->CriarSolicitanteAleatorio();

            int id = processos->IdProcesso();
            string data = processos->GerarDataAleatoria();
            string hora = processos->gerarHoraAleatoria();

            //Enviar para pilha AQUI
            
            string assuntos[] = { //falta mais
            "Requerimento de Documentos",
            "Revisao de Nota",
            "Solicitacao de Declaracao",
            "Pedido de Transferencia",
            "Solicitacao de suporte tecnicos de TI", "Revisao de Nota",
            "Solicitacao de Laboratorio",
            "Apresentar Justificativa de faltas",  "Requerimento de apresentacao de Trabalho de conclusao de curso", 
            "Requerimento de apresentacao de Relatorio de Pratica Profissional",
            "Requerimento para Trancamento de Curso", "Solicitacao de Readimicao"
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

                // caixa->empilhar(novoProcesso);
    }

    void Gerenciador::iniciarDia(){
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