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
        
        // Tenta tramitar 3 de alta prioridade
        for (int i = 0; i < 3 && npt > 0 && !listaAlta.isEmpty(); ++i) {
            Processos* p = listaAlta.removerDoInicio();
            std::cout << "Tramitado [ALTA]: Processo ID " << p->IdProcesso() << "\n";
            delete p;
            npt--;
        }

        // Tenta tramitar 2 de média prioridade (<<< CORRIGIDO >>>)
        for (int i = 0; i < 2 && npt > 0 && !listaMedia.isEmpty(); ++i) {
            // Remove e obtém o processo do início da lista
            Processos* p = listaMedia.remove(p);
            std::cout << "Tramitado [MEDIA]: Processo ID " << p->IdProcesso() << "\n";
            delete p;
            npt--;
        }

        // Tenta tramitar 1 de baixa prioridade (<<< CORRIGIDO >>>)
        if (npt > 0 && !listaBaixa.isEmpty()) { // Verifica a lista correta
            // Remove e obtém o processo do início da lista
            Processos* p = listaBaixa.remove();
            std::cout << "Tramitado [BAIXA]: Processo ID " << p->IdProcesso() << "\n";
            delete p;
            npt--;
        }
    }
}

void Gerenciador::imprimirPendentes() const {
    std::cout << "\n--- Relatorio de Pendencias (Fim do Dia) ---\n";
    std::cout << "Pendentes - ALTA PRIORIDADE:\n";
    // this->listaAlta.imprimir(); // Você precisará de um método de impressão nas suas listas
    std::cout << "Pendentes - MEDIA PRIORIDADE:\n";
    // this->listaMedia.print();
    std::cout << "Pendentes - BAIXA PRIORIDADE:\n";
    // this->listaBaixa.print();
}


// --- 3. MÉTODOS AUXILIARES ---
// As "habilidades" que os métodos acima usam.

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
    // Esta é a sua lógica de 'GerarProbabilidade', colocada no lugar certo.
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(0, 99);
    int sorteio = distrib(gen);

    if (sorteio < 10) return ALTA;  // 10%
    else if (sorteio < 40) return MEDIA; // 30%
    else return BAIXA;               // 60%
}

void Gerenciador::distribuirPrioridade(Processos* processo) {
    // Esta é a sua lógica de 'distribuirPrioridade', com o nome correto.
    switch (processo->getPrioridade()) {
        case ALTA:
            this->listaAlta.inserirNoFim(processo);
            break;
        case MEDIA:
            this->listaMedia.insert(processo); // Lembre-se que suas listas devem aceitar Processos*
            break;
        case BAIXA:
            this->listaBaixa.insert(processo); // Lembre-se que suas listas devem aceitar Processos*
            break;
    }
}

Pessoa* Gerenciador::criarSolicitanteAleatorio() {
    // Versão corrigida para evitar vazamento de memória.
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1);
    
    if (dist(gen) == 0) {
        return new Aluno(); // Só cria o Aluno se ele for escolhido
    } else {
        return new Professor(); // Ou só o Professor se ele for escolhido
    }
}