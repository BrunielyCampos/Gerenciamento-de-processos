 #include <iostream>
 #include "Pessoa.h"
 #include <random>
 
 using namespace std;

  Pessoa::Pessoa(double numMatricula,string cpf){
    this->numMatricula = GerarNumMatricula();
    this->cpf = GerarCpf();
  }

  // Pessoa::Pessoa(){
    

  // }

  double Pessoa::GerarNumMatricula(){
    static mt19937 gen(std::random_device{}()); 
    static uniform_int_distribution<int> dist(2024, 2999);
    
    return  (double) dist(gen);
  }

  string Pessoa::GerarCpf(){

      static mt19937 gen(random_device{}());
      uniform_int_distribution<> dist(0, 9);
      string cpf = "";  //atribui os numeros gerados para o cpf.

      for (int i = 0; i <= 11; i++){
      cpf += to_string(dist(gen));
  }
      return cpf;
      
  }