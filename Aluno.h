#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_

// Cabeçalho da classe Aluno.
// Contém a definição da classe Aluno que herda de Pessoa.

#include "Pessoa.h"
#include <vector>
#include <string>

using namespace std; // Atenção: usar namespace global em headers não é recomendado.

// Enumeração com os nomes dos cursos disponíveis.
enum NomeCurso {
    A_INFORMATICA,
    A_QUIMICA,
    A_ADM,
    A_ADMSUB,
    A_TADS,
    A_TPQ
};

// Declaração da classe Aluno que herda de Pessoa.
class Aluno : public Pessoa {
    private:
        NomeCurso curso;           // Campo que armazena o curso do aluno (valor da enum).
        string nome;               // Nome do aluno (string).
        Pessoa * pessoa = new Pessoa(); // Ponteiro para um objeto Pessoa inicializado aqui.
                                        // OBS: Alocar objetos diretamente em membros pode levar a problemas
                                        // de gerenciamento de memória (vazamentos) se não houver destrutor adequado.
    public:
        Aluno();                           // Construtor padrão da classe Aluno.
        vector<std::string> ListNomesAlunos(); // Método que retorna uma lista de nomes de alunos.
        string DefNomeCurso() const;       // Método que retorna o nome do curso como string (não modifica o objeto).
        int DefCurso();                    // Método que provavelmente retorna/define o código do curso (retorna int).
        void imprimirAluno();              // Método para imprimir os dados do aluno.
};

#endif