// Inclusão dos arquivos de cabeçalho necessários
#include "Gerenciador.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>
#include <random>

// Construtor padrão - inicializa com valores padrão para limites de processos
Gerenciador::Gerenciador() {
    namin = 5;  // Mínimo de processos abertos
    namax = 15; // Máximo de processos abertos
    ntmin = 8;  // Mínimo de processos tramitados
    ntmax = 20; // Máximo de processos tramitados
}

// Construtor com parâmetros personalizados
Gerenciador::Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados) {
    // Permite definir limites customizados
    namin = minAbertos;
    namax = maxAbertos;
    ntmin = minTramitados;
    ntmax = maxTramitados;
}

// Inicia a simulação para um número específico de dias
void Gerenciador::iniciarSimulacao(int dias) {
    for (int dia = 1; dia <= dias; ++dia) {
        std::cout << "\n=================== DIA " << dia << " ===================\n";
        this->executarUmDia();
    }
}

// Executa as atividades de um dia completo
void Gerenciador::executarUmDia() {
    this->abrirNovosProcessos();    // Fase da manhã
    this->organizarProcessos();      // Fase da tarde (parte 1)
    this->tramitarProcessos();       // Fase da tarde (parte 2)
    this->imprimirPendentes();       // Relatório final do dia
}

// Fase de abertura de novos processos (período da manhã)
void Gerenciador::abrirNovosProcessos() {
    std::cout << "\n--- Fase de Abertura (Manha) ---\n";
    int npa = this->gerarNPA(); // Gera número aleatório de processos a serem abertos
    std::cout << npa << " novos processos serao abertos.\n";

    // Cria e empilha os novos processos
    for (int i = 0; i < npa; ++i) {
        Processos* processoCriado = new Processos();
        PrioridadeProcessos pSorteada = this->sortearPrioridadeAleatoria();
        processoCriado->setPrioridade(pSorteada);
        processoCriado->imprimir();
        this->caixaDeProcessos.empilhar(processoCriado);
    }
}

// Organiza os processos nas filas de prioridade apropriadas
void Gerenciador::organizarProcessos() {
    std::cout << "\n--- Fase de Organizacao (Tarde) ---\n";
    // Desempilha e distribui cada processo para sua lista de prioridade
    while (!this->caixaDeProcessos.isEmpty()) {
        Processos* processo = this->caixaDeProcessos.Desempilhar();
        if (processo) {
            this->distribuirPrioridade(processo);
        }
    }
}

// Realiza a tramitação dos processos seguindo regras de prioridade
void Gerenciador::tramitarProcessos() {
    std::cout << "\n--- Fase de Tramitacao (Tarde) ---\n";
    int npt = this->gerarNPT(); // Gera número de processos que podem ser tramitados
    
    // Processa na ordem: 3 ALTA, 2 MÉDIA, 1 BAIXA, repetindo até acabar a capacidade
    while (npt > 0 && (!listaAlta.isEmpty() || !listaMedia.isEmpty() || !listaBaixa.isEmpty())) {
        // Código de tramitação para cada prioridade...
    }
}

// Métodos auxiliares para geração de números aleatórios e distribuição de processos

// Gera número aleatório de processos a serem abertos
int Gerenciador::gerarNPA() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(namin, namax);
    return distrib(gen);
}

// Gera número aleatório de processos a serem tramitados
int Gerenciador::gerarNPT() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(ntmin, ntmax);
    return distrib(gen);
}

// Sorteia uma prioridade aleatória com diferentes probabilidades
// 10% ALTA, 30% MÉDIA, 60% BAIXA
PrioridadeProcessos Gerenciador::sortearPrioridadeAleatoria() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(0, 99);
    int sorteio = distrib(gen);

    if (sorteio < 10) return ALTA;
    else if (sorteio < 40) return MEDIA;
    else return BAIXA;
}
