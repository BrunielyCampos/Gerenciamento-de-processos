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

    double Gerenciador::GerarProbabilidade(){
        
    }


    void Gerenciador::DistribuirPrioridade(Processos* processo);{
        
       
    }

    void Gerenciador::tramitarProcessos(){
        
    }

    int Gerenciador::gerarN_Processos(){
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(3, 15); //processos entre 3 e 15

        int n_processos = distrib(gen);
        n_Processos = n_processosGerado;
        return n_processos;
    }


    void Gerenciador::abrirProcesso(int nptProcessos, int npaProcessos){ //criar processos
    cout << "Recebendo Processos..." << "\n";

        Processos * processos = new Processos();
        
        for(int i = 0; i < n_processos; i++){

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

        /*
        
            Prioridade GerenciadorProcessos::getPrioridadeAleatoria() {
            // Versao SIMPLES e garantida de funcionar
            static int counter = 0;
            counter++;

            // Distribuicao fixa para teste: 1 Alta, 3 Media, 6 Baixa a cada 10 processos
            int mod = counter % 10;

            if (mod == 0) return Prioridade::ALTA;           // 10%
            else if (mod >= 1 && mod <= 3) return Prioridade::MEDIA; // 30%
            else return Prioridade::BAIXA;                   // 60%
        }

      string GerenciadorProcessos::getAssuntoAleatorio(Prioridade prioridade, const string& tipoSolicitante) {
            static int assuntoCounter = 0;
            assuntoCounter++;

            // Listas de assuntos por prioridade
            static vector<string> assuntosAlta = {
                "Problema urgente de sistema", "Falta critica de material", 
                "Problema de seguranca", "Emergencia academica",
                "Sistema indisponivel", "Acesso negado a recurso essencial"
            };

            static vector<string> assuntosMedia = {
                "Requisicao de documentos", "Duvida sobre disciplina",
                "Agendamento de aula", "Consulta de notas",
                "Alteracao de turma", "Justificativa de falta",
                "Certificado de conclusao", "Problema com frequencia"
            };

            static vector<string> assuntosBaixa = {
                "Informacao geral", "Sugestao de melhoria",
                "Consulta de horarios", "Material complementar",
                "Duvida sobre calendario", "Solicitacao de informacao",
                "Feedback sobre disciplina", "Consulta bibliografica"
            };

            const std::vector<std::string>* assuntos;

            switch(prioridade) {
                case Prioridade::ALTA: assuntos = &assuntosAlta; break;
                case Prioridade::MEDIA: assuntos = &assuntosMedia; break;
                case Prioridade::BAIXA: assuntos = &assuntosBaixa; break;
                default: assuntos = &assuntosBaixa;
            }

            int index = assuntoCounter % assuntos->size();
            return (*assuntos)[index];
        }
                
                */

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