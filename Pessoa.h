#include <string>

#ifndef _PESSOA_
#define _PESSOA_

using namespace std;

class Pessoa{

private:
    double numMatricula;
    string nome;
    string cpf;
    
public:
    Pessoa();
    Pessoa(double numMatricula, string nome, string cpf);

    double gerarNumMatricula(double numMatricula) const;
    string Nome(string nome) const;
    string Cpf(string cpf) const;

    void imprimir();

    // void setnumMatricula(double numMatricula);
    // void setNome(string nome);
    // void setCpf(string cpf);
    
};

#endif