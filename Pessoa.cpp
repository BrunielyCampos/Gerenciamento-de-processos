 #include <iostream>
 #include "Pessoa.h"
 
 using namespace std;

 double Pessoa::NumMatricula(double numMatricula) const{
    cout << "Digite a sua matricula: ";
    cin >> numMatricula; 
 }
string Pessoa::Nome(string nome) const{
    cout << "Digite o seu nome: ";
    cin >> nome;   
}
string Pessoa::Cpf(string cpf) const{
     cout << "Digite o seu CPF: ";
    cin >> cpf; 
}

void Pessoa::imprimir(){

    cout << "Nome: " << this->nome;
    cout << "Cpf: " << this->cpf;
    cout << "Matricula: " << this->numMatricula;
   

}