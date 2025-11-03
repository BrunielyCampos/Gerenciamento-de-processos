#ifndef _PROFESSOR_HPP_  // Guarda de inclusão para evitar inclusões múltiplas
#define _PROFESSOR_HPP_

#include <string>        // Inclusão da biblioteca string
#include "Pessoa.h"      // Inclusão da classe base Pessoa

using namespace std;

// Enumeração para definir as possíveis áreas de atuação do professor
enum AtuacaoProfessor{
    P_INFORMATICA,       // Professor de Informática
    P_ADMINISTRACAO,     // Professor de Administração
    P_PROPEDEUTICA,      // Professor de Propedêutica
    P_QUIMICA           // Professor de Química
};

// Classe Professor que herda da classe Pessoa
class Professor : public Pessoa {
    private:
        AtuacaoProfessor especialidade;  // Atributo que armazena a especialidade do professor

    public:
        Professor();                      // Construtor padrão

        int Especialidade();              // Método para obter a especialidade

        string ListaNomeProf();           // Método para listar o nome do professor

        string DefEspecialidade();        // Método para definir a especialidade

        void ImprimirProfessor();        // Método para imprimir dados do professor
};
#endif