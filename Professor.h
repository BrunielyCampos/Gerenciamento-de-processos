#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_

#include <string>
#include "Pessoa.h"

class Professor : public Pessoa {
    private:

        string especialidade;

    public:

    Professor();

    Professor(string especialidade);
    
    string getEspecialidade() const;

    void setEspecialidade(string especialidade);

    
};

#endif