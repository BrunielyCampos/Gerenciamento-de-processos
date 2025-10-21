#include <string>

#ifndef _PESSOA_
#define _PESSOA_

using namespace std;

class Pessoa{

private:
    double numMatricula;
    string cpf;
    
public:
    Pessoa();
    Pessoa(double numMatricula, string cpf);

    double GerarNumMatricula();
    string GerarCpf();
};

#endif