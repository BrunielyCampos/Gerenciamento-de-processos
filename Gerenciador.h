#ifndef GERENCIADOR_H
#define GERENCIADOR_H

// <<< ALTERAÇÃO AQUI: Incluímos todas as dependências que o Gerenciador controla >>>
#include "CaixaDeProcessos.h"
#include "ListaSimples.h"
#include "ListaDuplaMedia.h"
#include "ListaDuplaBaixa.h"
#include "Processos.h" // A classe Processos em si
#include "Pessoa.h"   // Para poder criar Alunos e Professores

class Gerenciador {
public:
    // Construtor para definir os parâmetros da simulação
    Gerenciador();

    // <<< ALTERAÇÃO AQUI: Este é o único método público que a main vai chamar >>>
    void iniciarSimulacao(int dias);

private:
    // <<< ALTERAÇÃO CRÍTICA AQUI: O Gerenciador agora "TEM" as estruturas de dados como membros >>>
    // Elas existem durante toda a vida do objeto Gerenciador.
    CaixaDeProcessos caixaDeProcessos;
    ListaSimples listaAlta;
    ListaDuplaMedia listaMedia;
    ListaDuplaBaixa listaBaixa;

    // Parâmetros da simulação
    int namin, namax, ntmin, ntmax;

    // <<< ALTERAÇÃO AQUI: A lógica foi dividida em métodos privados e organizados >>>
    // Isso segue o Princípio da Responsabilidade Única.
    Gerenciador(int minAbertos, int maxAbertos, int minTramitados, int maxTramitados)
    void executarUmDia();
    void abrirNovosProcessos();
    void organizarProcessos();
    void tramitarProcessos();
    void imprimirPendentes() const;

    // Métodos auxiliares que ajudam os principais
    Pessoa* criarSolicitanteAleatorio();
    void distribuirPrioridade(Processos* processo);
    // ... outros métodos que você possa precisar
};

#endif // GERENCIADOR_H