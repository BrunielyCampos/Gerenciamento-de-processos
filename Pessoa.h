#include <string>

// Guarda múltiplas inclusões deste ficheiro
#ifndef _PESSOA_
#define _PESSOA_

using namespace std;

// Classe que representa uma pessoa com matrícula e CPF
class Pessoa {

private:
    int numMatricula; // número de matrícula da pessoa
    string cpf;       // CPF da pessoa (armazenado como string)

public:
    Pessoa();                         // construtor padrão
    Pessoa(int numMatricula, string cpf); // construtor que inicializa matrícula e CPF

    int GerarNumMatricula(); // método para gerar/obter número de matrícula
    string GerarCpf();       // método para gerar/obter CPF
};

#endif // _PESSOA_