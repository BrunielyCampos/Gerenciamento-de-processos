 #include <iostream>
 #include "Pessoa.h"
 #include <random>
 #include <ctime>
 
 using namespace std;

 Pessoa::Pessoa(double numMatricula,string cpf){
   numMatricula = GerarNumMatricula();
   cpf = GerarCpf();
 }

double Pessoa::GerarNumMatricula(){
  static std::mt19937 gen(std::random_device{}()); 
  static std::uniform_int_distribution<int> dist(1000000, 9999999);

  return dist(gen);
 }

string Pessoa::GerarCpf(){

    static mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(0, 9);
    string cpf = "";  //atribui os numeros gerados para o cpf.

    for (int i = 0; i <= 11; i++){
     cpf += to_string(dist(gen));
    }
    
}