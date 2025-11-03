#include "Processos.h"
#include "CaixaDeProcessos.h"
#include "Gerenciador.h"
#include <random>
#include <sstream> 
#include <iomanip>
#include <iostream>

using namespace std;

 #include "Processos.h"
#include <random>    // Essencial para números aleatórios
#include <sstream>   // Essencial para formatar strings
#include <iomanip>   // Essencial para formatar strings
#include <iostream>


Processos::Processos() {

    this->idGerado = this->IdProcesso();
    this->dataAbertura = this->GerarDataAleatoria();
    this->horaAbertura = this->GerarHoraAleatoria();
    this->prioridade = PrioridadeProcessos::BAIXA;
    this->assunto = "Assunto a ser definido";
}

    int Processos::IdProcesso(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(1000, 9999);

        int idGerado = distrib(gen);
        return idGerado;
    }
    
    string Processos::GerarDataAleatoria (){
        uniform_int_distribution<int> distDia(1, 31);
        uniform_int_distribution<int> distMes(1, 12);

        //
        mt19937 engine;

        int dia = distDia(engine);
        int mes = distMes(engine);

        std::ostringstream dataAbertura;
        dataAbertura << dia << "/" << mes;
        return dataAbertura.str();
    }

    string Processos::GerarHoraAleatoria(){
        uniform_int_distribution<int> distHora(8, 11);
        uniform_int_distribution<int> distMinSeg(0, 59);
    
        mt19937 engine;

        int hora = distHora(engine);
        int minuto = distMinSeg(engine);
        int segundo = distMinSeg(engine);

        stringstream horaAbertura;
        horaAbertura << setw(2) << setfill('0') << hora << ":"
        << setw(2) << setfill('0') << minuto << ":"
        << setw(2) << setfill('0') << segundo;

        return horaAbertura.str();
    }

    void Processos::setPrioridade(PrioridadeProcessos p) {
        this->prioridade = p;
    }

    PrioridadeProcessos Processos::getPrioridade() {
        return this->prioridade;
    }


    void Processos::imprimir() {
        // A lógica para converter o enum em texto fica aqui dentro,
        // simplificando a interface da classe.
        std::string prioridadeTexto;
        switch (this->prioridade) {
            case PrioridadeProcessos::ALTA:
                prioridadeTexto = "Alta";
                break;
            case PrioridadeProcessos::MEDIA:
                prioridadeTexto = "Media";
                break;
            case PrioridadeProcessos::BAIXA:
                prioridadeTexto = "Baixa";
                break;
        }

        std::cout << "----------------------------------------\n";
        std::cout << "ID do Processo: " << this->idGerado<< "\n";
        std::cout << "Prioridade:     " << prioridadeTexto << "\n";
        std::cout << "Abertura:       " << this->dataAbertura << " as " << this->horaAbertura << "\n";
        std::cout << "----------------------------------------\n";
    }