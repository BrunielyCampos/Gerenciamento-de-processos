#include "Professor.h"
    
    Professor::Professor(){

    }
    
    int Professor::Especialidade(AtuacaoProfessor especialidade) const{
        return especialidade;
    }

    void Professor::setEspecialidade(string especialidade){
        if (especialidade == "INFORMÁTICA"){
            this->especialidade = INFORMÁTICA;
        }
        else if (especialidade == "ADMINISTRAÇÃO"){
            this->especialidade = ADMINISTRAÇÃO;
        }
        else if (especialidade == "PROPEDÊUTICA"){
            this->especialidade = PROPEDÊUTICA;
        }
        else if (especialidade == "QUÍMICA"){
            this->especialidade = QUÍMICA;
        }
    }