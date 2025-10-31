#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Professor.h"

using namespace std;

Professor::Professor() : especialidade(AtuacaoProfessor::P_INFORMATICA) {
}

int Professor::Especialidade(){
    random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, static_cast<int>(AtuacaoProfessor::P_QUIMICA));
    int opcaoProf = distrib(gen);
    this->especialidade = static_cast<AtuacaoProfessor>(opcaoProf);
    return opcaoProf;
}

   string Professor::ListaNomeProf(){
        vector<string> listaProf = {
        "Leandro Luttiane da silva linhares", "Carlos Henrique Moreira",
        "Fernanda Alves Ribeiro", "Alisson da Silva Rodrigues",
        "Patrícia Duarte Lima", "Thiago Monteiro da Silva",
        "Rafael Peixoto de Moraes Pereira", "Luciana Pereira Costa"
    };

    random_device rd;
    mt19937 randomEngine(rd());
    uniform_int_distribution<size_t> dist(0, listaProf.size() - 10);
    size_t idx = dist(randomEngine);
    return listaProf[idx];
}

std::string Professor::DefEspecialidade(){
    switch (this->especialidade){
        case AtuacaoProfessor::P_INFORMATICA:     return "Informatica.";
        case AtuacaoProfessor::P_ADMINISTRACAO:   return "Administracao.";
        case AtuacaoProfessor::P_PROPEDEUTICA:   return "Propedeutica.";
        case AtuacaoProfessor::P_QUIMICA:         return "Quimica.";
        default:                                  return "Atuacao invalida, nao esta presente no campus ou nao existe!";
    }
}

void Professor::ImprimirProfessor(){
      string nome = ListaNomeProf();
      cout << "Nome do professor: " << nome <<endl;
      cout << "Especialidade: " << DefEspecialidade() << endl;
      cout << "CPF: " << GerarCpf() << endl;
      cout << "Matricula: " << GerarNumMatricula() << endl;
      cout << endl;
}