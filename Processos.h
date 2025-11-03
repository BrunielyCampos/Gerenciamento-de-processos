#ifndef PROCESSOS_H
#define PROCESSOS_H

#include <string>
#include <random>

enum PrioridadeProcessos {
    BAIXA,
    MEDIA,
    ALTA
};

class Processos {
private:
    // --- ATRIBUTOS PRIVADOS ---
    int id;
    std::string dataAbertura;
    std::string horaAbertura;
    PrioridadeProcessos prioridade;
    std::string assunto;

    // --- MOTOR ESTÁTICO COMPARTILHADO ---
    static std::mt19937 engine;

    // --- MÉTODOS PRIVADOS AUXILIARES ---
    int gerarIdUnico();
    std::string gerarDataAleatoria();
    std::string gerarHoraAleatoria();

public:
    // --- MÉTODOS PÚBLICOS ---

    // Construtor que monta o objeto.
    Processos();
    
    // Getters para permitir a leitura segura dos dados.
    int IdProcessos() const;
    PrioridadeProcessos getPrioridade() const;

    // Setter para permitir a alteração segura da prioridade.
    void setPrioridade(PrioridadeProcessos p);

    // Método para exibir as informações do processo.
    void imprimir() const;
};

#endif // PROCESSOS_H