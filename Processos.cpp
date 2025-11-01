#include "Processos.h"
#include "CaixaDeProcessos.h"
#include <random>
#include <sstream> 
#include <iomanip>

using namespace std;



    Processos::Processos(){
        
    }
    

    /*int Processos::idProcesso (int idProcesso) const{
        random_device rd;
        static mt19937 gend());
        uniform_int_distribution<int> distrib(1000, 9999);

        int idGerado = distrib(gen);
        this->idProcesso = idGerado;

        return idGerado;
    }*/
    
    string Processos::GerarDataAleatoria (){
        uniform_int_distribution<int> distDia(1, 31);
        uniform_int_distribution<int> distMes(1, 12);

        int dia = distDia(engine);
        int mes = distMes(engine);

        std::ostringstream oss;
        oss << dia << ":" << mes;
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

    void Processos::abrirProcesso(int nptProcessos, int npaProcessos){
        
    }

    void Processos::imprimir() const{

    }