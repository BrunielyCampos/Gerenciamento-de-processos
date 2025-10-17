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

    double getnumMatricula() const;
    string getNome() const;
    string getCpf() const;

    void setnumMatricula(double numMatricula);
    void setNome(string nome);
    void setCpf(string cpf);
    
};

#endif