#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Professor.h"

using namespace std;

// Construtor padrão - inicializa a especialidade como Informática
Professor::Professor() : especialidade(AtuacaoProfessor::P_INFORMATICA) {
}

// Gera aleatoriamente uma especialidade para o professor
int Professor::Especialidade(){
    random_device rd;
    static mt19937 gen(rd()); // Gerador de números aleatórios Mersenne Twister
    uniform_int_distribution<int> distrib(0, static_cast<int>(AtuacaoProfessor::P_QUIMICA));
    int opcaoProf = distrib(gen);
    this->especialidade = static_cast<AtuacaoProfessor>(opcaoProf);
    return opcaoProf;
}

// Retorna aleatoriamente um nome da lista de professores
string Professor::ListaNomeProf(){
    // Lista de nomes de professores disponíveis
    vector<string> listaProf = {
        "Leandro Luttiane da silva linhares", "Carlos Henrique Moreira",
        "Fernanda Alves Ribeiro", "Alisson da Silva Rodrigues",
        "Patrícia Duarte Lima", "Thiago Monteiro da Silva",
        "Rafael Peixoto de Moraes Pereira", "Luciana Pereira Costa"
    };

    // Geração aleatória do índice para selecionar um nome
    random_device rd;
    mt19937 randomEngine(rd());
    uniform_int_distribution<size_t> dist(0, listaProf.size() - 10);
    size_t idx = dist(randomEngine);
    return listaProf[idx];
}

// Converte o enum da especialidade para uma string correspondente
std::string Professor::DefEspecialidade(){
    switch (this->especialidade){
        case AtuacaoProfessor::P_INFORMATICA:     return "Informatica.";
        case AtuacaoProfessor::P_ADMINISTRACAO:   return "Administracao.";
        case AtuacaoProfessor::P_PROPEDEUTICA:    return "Propedeutica.";
        case AtuacaoProfessor::P_QUIMICA:         return "Quimica.";
        default:                                   return "Atuacao invalida, nao esta presente no campus ou nao existe!";
    }
}

// Imprime todas as informações do professor
void Professor::ImprimirProfessor(){
      string nome = ListaNomeProf();
      cout << "Nome do professor: " << nome <<endl;
      cout << "Especialidade: " << DefEspecialidade() << endl;
      cout << "CPF: " << GerarCpf() << endl;
      cout << "Matricula: " << GerarNumMatricula() << endl;
      cout << endl;
}