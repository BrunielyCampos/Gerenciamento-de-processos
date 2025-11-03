#ifndef GERENCIADOR_H
#define GERENCIADOR_H

// Inclusão dos cabeçalhos necessários
#include "CaixaDeProcessos.h"
#include "ListaSimples.h"
#include "ListaDuplaMedia.h"
#include "ListaDuplaBaixa.h"
#include "Processos.h"
#include "Pessoa.h"

// Classe responsável pelo gerenciamento dos processos
class Gerenciador {
public:
    // Construtores
    Gerenciador(); // Construtor padrão
    // Construtor com parâmetros para definir limites de processos abertos e tramitados
    Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados); 

    // Método para iniciar a simulação com número específico de dias
    void iniciarSimulacao(int dias);

private:
    // Estruturas de dados para armazenamento dos processos
    CaixaDeProcessos caixaDeProcessos;
    ListaSimples listaAlta;      // Lista para processos de alta prioridade
    ListaDuplaMedia listaMedia;  // Lista para processos de média prioridade
    ListaDuplaBaixa listaBaixa;  // Lista para processos de baixa prioridade

    // Variáveis para controle de limites de processos
    int namin, namax;  // Mínimo e máximo de processos abertos
    int ntmin, ntmax;  // Mínimo e máximo de processos tramitados

    // Métodos auxiliares para a simulação
    void executarUmDia();              // Executa as operações de um dia
    void abrirNovosProcessos();        // Cria novos processos
    void organizarProcessos();         // Organiza os processos nas listas
    void tramitarProcessos();          // Realiza a tramitação dos processos
    void imprimirPendentes() const;    // Exibe processos pendentes

    // Métodos para geração de números aleatórios
    int gerarNPA();                    // Gera número de processos a serem abertos
    int gerarNPT();                    // Gera número de processos a serem tramitados

    // Métodos para manipulação de prioridades
    PrioridadeProcessos sortearPrioridadeAleatoria();  // Sorteia uma prioridade
    void distribuirPrioridade(Processos* processo);     // Distribui processo na lista correta

    // Método para criar solicitante aleatório
    Pessoa* criarSolicitanteAleatorio();
};

#endif