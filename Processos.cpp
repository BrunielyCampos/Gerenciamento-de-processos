#include "Processos.h"
#include "CaixaDeProcessos.h"
#include <random>


    Processos::Processos(){
        
    }

    /*int Processos::idProcesso (int idProcesso) const{
        random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distrib(1000, 9999);

        int idGerado = distrib(gen);
        this->idProcesso = idGerado;
        return idGerado;
    }*/

    int Processos::data (int processo) const{
        random_device rd;
        static mt19937 gen(rd());

        uniform_int_distribution<int> distrib(1, 30);

        int dataGerado = distrib(gen);
        this->m_data = dataGerado;
        return dataGerado;
    }

    

    int Processos::hora (int processo) const{
        random_device rd;
        static mt19937 gen(rd());

        uniform_int_distribution<int> distrib(0, 1);
    
        
        
        return;
    }

    void Processos::abrirProcesso(int nptProcessos, int npaProcessos){
        
    }

/*
    Gerenciamento::Gerenciamento() {
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    randomEngine.seed(seed);
}

// Inicializa o motor de aleatoriedade (caso precise reiniciar)
void Gerenciamento::inicializarAleatoriedade() {
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    randomEngine.seed(seed);
}

// Configura parâmetros de probabilidade e intervalos
void Gerenciamento::configurarParametros(double pAlta, double pMedia, double pBaixa,
                                         int minAbertos, int maxAbertos,
                                         int minTramitados, int maxTramitados) {
    pA = pAlta;
    pM = pMedia;
    pB = pBaixa;
    namin = minAbertos;
    namax = maxAbertos;
    ntmin = minTramitados;
    ntmax = maxTramitados;
}

// Gera valores aleatórios para quantidades de processos
void Gerenciamento::gerarQuantidades() {
    uniform_int_distribution<int> distAbertos(namin, namax);
    uniform_int_distribution<int> distTramitados(ntmin, ntmax);

    processosAbertos = distAbertos(randomEngine);
    processosTramitados = distTramitados(randomEngine);

    cout << "📊 Quantidades do dia:\n";
    cout << " - Processos abertos: " << processosAbertos << endl;
    cout << " - Processos tramitados: " << processosTramitados << endl;
}

// Simula prioridades de cada processo aberto
void Gerenciamento::simularPrioridades() {
    uniform_real_distribution<double> distProb(0.0, 1.0);

    cout << "\n🎯 Distribuição de prioridades:\n";
    for (int i = 0; i < processosAbertos; ++i) {
        double sorteio = distProb(randomEngine);

        string prioridade;
        if (sorteio < pA)
            prioridade = "Alta";
        else if (sorteio < pA + pM)
            prioridade = "Média";
        else
            prioridade = "Baixa";

        cout << " → Processo " << i + 1 << ": " << prioridade << endl;
    }
}

// Método que executa tudo junto
void Gerenciamento::executarSimulacao() {
    gerarQuantidades();
    simularPrioridades();
}*/

     //recebe alguma referência do poteiro da pilha


    void Processos::imprimir() const{

    }