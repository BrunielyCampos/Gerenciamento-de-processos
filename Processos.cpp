#include "Processos.h"
#include <iostream>
#include <sstream> 
#include <iomanip>

// --- INICIALIZAÇÃO DO MOTOR ESTÁTICO ---
// O motor de números aleatórios (std::mt19937) é declarado como membro estático
// na classe (Processos::engine) e aqui é inicializado UMA VEZ no .cpp.
// std::random_device{}() fornece uma semente diferente a cada execução (quando disponível).
std::mt19937 Processos::engine(std::random_device{}());

// --- CONSTRUTOR ---
// Inicializa um objeto Processos usando métodos PRIVADOS que geram valores iniciais.
Processos::Processos() {
    // Gera um ID único aleatório para o processo
    this->id = this->gerarIdUnico();
    // Gera data e hora de abertura aleatórias
    this->dataAbertura = this->gerarDataAleatoria();
    this->horaAbertura = this->gerarHoraAleatoria();
    // Inicializa prioridade e assunto com valores padrão
    this->prioridade = PrioridadeProcessos::BAIXA;
    this->assunto = "N/A";
}

// --- MÉTODOS PRIVADOS (Implementação) ---

// Gera um ID inteiro aleatório no intervalo [1000, 9999].
// Usa a engine estática compartilhada para garantir aleatoriedade consistente.
int Processos::gerarIdUnico() {
    std::uniform_int_distribution<int> distrib(1000, 9999);
    return distrib(engine); // Usa o motor compartilhado
}
    
// Gera uma string com data no formato "DD/MM" com dia entre 1 e 28 e mês entre 1 e 12.
// Usa distribuições separadas para dia e mês e formata com dois dígitos.
std::string Processos::gerarDataAleatoria() {
    std::uniform_int_distribution<int> distDia(1, 28);
    std::uniform_int_distribution<int> distMes(1, 12);

    int dia = distDia(engine); // Usa o motor compartilhado
    int mes = distMes(engine); // Usa o motor compartilhado

    std::ostringstream oss;
    // setw(2) e setfill('0') garantem formatação com dois dígitos (ex: "05/09")
    oss << std::setw(2) << std::setfill('0') << dia << "/" << std::setw(2) << std::setfill('0') << mes;
    return oss.str();
}

// Gera uma string com hora no formato "HH:MM:SS".
// Hora entre 8 e 11; minutos e segundos entre 0 e 59.
// Formata sempre com dois dígitos por campo.
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

// Define a prioridade do processo.
void Processos::setPrioridade(PrioridadeProcessos p) {
    this->prioridade = p;
}

// Retorna a prioridade atual.
PrioridadeProcessos Processos::getPrioridade() const {
    return this->prioridade;
}

// Retorna o ID do processo.
int Processos::IdProcessos() const {
    return this->id;
}

// Imprime informações do processo no console.
// Converte o enum PrioridadeProcessos para texto e exibe dados formatados.
void Processos::imprimir() const {
    std::string prioridadeTexto;
    switch (this->prioridade) {
        case ALTA:  prioridadeTexto = "Alta";  break;
        case MEDIA: prioridadeTexto = "Media"; break;
        case BAIXA: prioridadeTexto = "Baixa"; break;
    }

    std::cout << "----------------------------------------\n";
    std::cout << "ID do Processo: " << this->id << "\n"; // Exibe o ID
    std::cout << "Prioridade:     " << prioridadeTexto << "\n";
    std::cout << "Abertura:       " << this->dataAbertura << " as " << this->horaAbertura << "\n";
    std::cout << "----------------------------------------\n";
}