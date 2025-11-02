#include "Processos.h"
#include "CaixaDeProcessos.h"
#include "Gerenciador.h"
#include <random>
#include <sstream> 
#include <iomanip>
#include <iostream>

using namespace std;



    Processos::Processos(){
        random_device rd;
        engine.seed(rd()); //garantir aleatoridade
    }

    int Processos::IdProcesso(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(1000, 9999);

        int idGerado = distrib(gen);
        return idGerado;
    }
    
    string Processos::GerarDataAleatoria (){
        uniform_int_distribution<int> distDia(1, 31);
        uniform_int_distribution<int> distMes(1, 12);

        //
        // t19937 dataEngine;

        int dia = distDia(engine);
        int mes = distMes(engine);

        std::ostringstream oss;
        oss << dia << "/" << mes;
        return oss.str();
    }

    string Processos::gerarHoraAleatoria(){
        uniform_int_distribution<int> distHora(8, 11);
        uniform_int_distribution<int> distMinSeg(0, 59);
    
        int hora = distHora(engine);
        int minuto = distMinSeg(engine);
        int segundo = distMinSeg(engine);

        stringstream ss;
        ss << setw(2) << setfill('0') << hora << ":"
        << setw(2) << setfill('0') << minuto << ":"
        << setw(2) << setfill('0') << segundo;

        return ss.str();
    }

    void Processos::imprimir() const{ //Ver se precisa
        cout << "Quantidade de processos abertos: " << "\n";
        cout << "Quantidade de processos tramitados: " << "\n";
    }