#include <iostream>
#include "Pessoa.h"
#include <random>    // Biblioteca para geração de números aleatórios
#include <ctime>    // Biblioteca para funções relacionadas a tempo
 
using namespace std;

// Construtor da classe Pessoa que recebe número de matrícula e CPF como parâmetros
Pessoa::Pessoa(int numMatricula, string cpf){
  numMatricula = GerarNumMatricula();  // Gera um número de matrícula aleatório
  cpf = GerarCpf();                    // Gera um CPF aleatório
}

// Construtor padrão da classe Pessoa (sem parâmetros)
Pessoa::Pessoa(){

}

// Método para gerar número de matrícula aleatório
int Pessoa::GerarNumMatricula(){
   static mt19937 gen(random_device{}());  // Gerador de números aleatórios Mersenne Twister
   static uniform_int_distribution<int> dist(1000000, 9999999);  // Distribui números uniformemente entre 1000000 e 9999999

   return dist(gen);  // Retorna um número aleatório gerado
}

// Método para gerar CPF aleatório
string Pessoa::GerarCpf(){
   static mt19937 gen(random_device{}());  // Gerador de números aleatórios Mersenne Twister
   uniform_int_distribution<> dist(0, 9);  // Distribui números uniformemente entre 0 e 9
   string cpf = "";  // String para armazenar o CPF gerado

   // Gera 12 dígitos aleatórios para o CPF
   for (int i = 0; i <= 11; i++){
    cpf += to_string(dist(gen));
   }
   
   return cpf;  // Retorna o CPF gerado
}