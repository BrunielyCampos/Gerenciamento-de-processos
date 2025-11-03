#include "Processos.h"
#include <iostream>
#include <sstream> 
#include <iomanip>

// --- INICIALIZAÇÃO DO MOTOR ESTÁTICO ---
// Esta linha fica no .cpp e garante que o motor seja criado e semeado UMA VEZ.
std::mt19937 Processos::engine(std::random_device{}());

// --- CONSTRUTOR ---
Processos::Processos() {
    // Chama os métodos PRIVADOS para se auto-inicializar.
    this->id = this->gerarIdUnico();
    this->dataAbertura = this->gerarDataAleatoria();
    this->horaAbertura = this->gerarHoraAleatoria();
    this->prioridade = PrioridadeProcessos::BAIXA;
    this->assunto = "N/A";
}

// --- MÉTODOS PRIVADOS (Implementação) ---

int Processos::gerarIdUnico() {
    std::uniform_int_distribution<int> distrib(1000, 9999);
    return distrib(engine); // Usa o motor compartilhado
}
    
std::string Processos::gerarDataAleatoria() {
    std::uniform_int_distribution<int> distDia(1, 28);
    std::uniform_int_distribution<int> distMes(1, 12);

    int dia = distDia(engine); // Usa o motor compartilhado
    int mes = distMes(engine); // Usa o motor compartilhado

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << dia << "/" << std::setw(2) << std::setfill('0') << mes;
    return oss.str();
}

std::string Processos::gerarHoraAleatoria() {
    std::uniform_int_distribution<int> distHora(8, 11);
    std::uniform_int_distribution<int> distMinSeg(0, 59);

    int hora = distHora(engine);       // Usa o motor compartilhado
    int minuto = distMinSeg(engine);   // Usa o motor compartilhado
    int segundo = distMinSeg(engine);  // Usa o motor compartilhado

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hora << ":"
       << std::setw(2) << std::setfill('0') << minuto << ":"
       << std::setw(2) << std::setfill('0') << segundo;
    return ss.str();
}

// --- MÉTODOS PÚBLICOS (Implementação) ---

void Processos::setPrioridade(PrioridadeProcessos p) {
    this->prioridade = p;
}

PrioridadeProcessos Processos::getPrioridade() const {
    return this->prioridade;
}

int Processos::IdProcessos() const {
    return this->id;
}

void Processos::imprimir() const {
    std::string prioridadeTexto;
    switch (this->prioridade) {
        case ALTA:  prioridadeTexto = "Alta";  break;
        case MEDIA: prioridadeTexto = "Media"; break;
        case BAIXA: prioridadeTexto = "Baixa"; break;
    }

    std::cout << "----------------------------------------\n";
    std::cout << "ID do Processo: " << this->id << "\n"; // 
    std::cout << "Prioridade:     " << prioridadeTexto << "\n";
    std::cout << "Abertura:       " << this->dataAbertura << " as " << this->horaAbertura << "\n";
    std::cout << "----------------------------------------\n";
}