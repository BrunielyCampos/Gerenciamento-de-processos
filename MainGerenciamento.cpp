#include <iostream>
#include <ctime>         // Necessário para a função time()
#include "Gerenciador.h"

using namespace std;

int main() {
    
    srand(time(NULL));

   
    cout << "==========================================" << std::endl;
    cout << "  Iniciando Simulacao de Processos" << std::endl;
    cout << "==========================================" << std::endl;


    Gerenciador sistema;


    sistema.iniciarSimulacao(3);

   
    cout << "\n==========================================" << std::endl;
    cout << "          Simulacao Finalizada" << std::endl;
    cout << "==========================================" << std::endl;

    
    return 0;
        
}