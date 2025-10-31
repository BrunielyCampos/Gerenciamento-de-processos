#include <string>

#ifndef _PESSOA_
#define _PESSOA_

using namespace std;

class Pessoa{

private:
    int numMatricula;
    string cpf;
    
public:
    Pessoa();
    Pessoa(int numMatricula, string cpf);

    int GerarNumMatricula();
    string GerarCpf();
};

#endif