#include "Gerenciador.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>
#include <random>

Gerenciador::Gerenciador() {

    namin = 5;
    namax = 15;
    ntmin = 8;
    ntmax = 20;
}

Gerenciador::Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados) {
    namin = minAbertos;
    namax = maxAbertos;
    ntmin = minTramitados;
    ntmax = maxTramitados;
}

void Gerenciador::iniciarSimulacao(int dias) {
    for (int dia = 1; dia <= dias; ++dia) {
        std::cout << "\n=================== DIA " << dia << " ===================\n";
        this->executarUmDia();
    }
}

void Gerenciador::executarUmDia() {
    this->abrirNovosProcessos();
    this->organizarProcessos();
    this->tramitarProcessos();
    this->imprimirPendentes();
}

void Gerenciador::abrirNovosProcessos() {
    std::cout << "\n--- Fase de Abertura (Manha) ---\n";
    int npa = this->gerarNPA(); // Pergunta: "Quantos processos abrimos hoje?"
    std::cout << npa << " novos processos serao abertos.\n";

    for (int i = 0; i < npa; ++i) {
       
        Processos* processoCriado = new Processos();
        
      
        PrioridadeProcessos pSorteada = this->sortearPrioridadeAleatoria();
        
       
        processoCriado->setPrioridade(pSorteada);

      
        processoCriado->imprimir();

       
        this->caixaDeProcessos.empilhar(processoCriado);
    }
}

void Gerenciador::organizarProcessos() {
    std::cout << "\n--- Fase de Organizacao (Tarde) ---\n";
    while (!this->caixaDeProcessos.isEmpty()) {
       
        Processos* processo = this->caixaDeProcessos.Desempilhar();
        
        
        if (processo) {
           
            this->distribuirPrioridade(processo);
        }
    }
    std::cout << "Processos distribuidos nas listas de prioridade.\n";
}

void Gerenciador::tramitarProcessos() {
    std::cout << "\n--- Fase de Tramitacao (Tarde) ---\n";
    int npt = this->gerarNPT();
    std::cout << "Capacidade de tramitacao para hoje: " << npt << " processos.\n\n";

    while (npt > 0 && (!listaAlta.isEmpty() || !listaMedia.isEmpty() || !listaBaixa.isEmpty())) {
        
        for (int i = 0; i < 3 && npt > 0 && !listaAlta.isEmpty(); ++i) {
            Processos* p = listaAlta.removerDoInicio();
            std::cout << "Tramitado [ALTA]: Processo ID " << p->IdProcessos() << "\n";
            delete p;
            npt--;
        }

        for (int i = 0; i < 2 && npt > 0 && !listaMedia.isEmpty(); ++i) {
    
            Processos* p = listaMedia.remove(p);
            std::cout << "Tramitado [MEDIA]: Processo ID " << p->IdProcessos() << "\n";
            delete p;
            npt--;
        }

      
        if (npt > 0 && !listaBaixa.isEmpty()) { 
            Processos* p = listaBaixa.remove();
            std::cout << "Tramitado [BAIXA]: Processo ID " << p->IdProcessos() << "\n";
            delete p;
            npt--;
        }
    }
}

void Gerenciador::imprimirPendentes() const {
    std::cout << "\n--- Relatorio de Pendencias (Fim do Dia) ---\n";
    std::cout << "Pendentes - ALTA PRIORIDADE:\n";
    std::cout << "Pendentes - MEDIA PRIORIDADE:\n";
    std::cout << "Pendentes - BAIXA PRIORIDADE:\n";
}



int Gerenciador::gerarNPA() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(namin, namax);
    return distrib(gen);
}

int Gerenciador::gerarNPT() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(ntmin, ntmax);
    return distrib(gen);
}

PrioridadeProcessos Gerenciador::sortearPrioridadeAleatoria() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(0, 99);
    int sorteio = distrib(gen);

    if (sorteio < 10) return ALTA;  
    else if (sorteio < 40) return MEDIA; 
    else return BAIXA;              
}

void Gerenciador::distribuirPrioridade(Processos* processo) {
   
    switch (processo->getPrioridade()) {
        case ALTA:
            this->listaAlta.inserirNoFim(processo);
            break;
        case MEDIA:
            this->listaMedia.insert(processo); 
            break;
        case BAIXA:
            this->listaBaixa.insert(processo); 
            break;
    }
}

Pessoa* Gerenciador::criarSolicitanteAleatorio() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1);
    
    if (dist(gen) == 0) {
        return new Aluno(); 
    } else {
        return new Professor();
    }
}