#include "Aluno.h"
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

   // Construtor da classe Aluno que chama o método para imprimir informações do aluno
   Aluno::Aluno(){  
      imprimirAluno();
   }

   // Método que define aleatoriamente o curso do aluno
   int Aluno::DefCurso(){
      // Configuração do gerador de números aleatórios
      random_device rd;
      static mt19937 gen(rd());

      // Distribuição uniforme entre 0 e o último índice dos cursos disponíveis
      uniform_int_distribution<int> distrib(0, static_cast<int>(NomeCurso::A_TPQ));
   
      // Gera e atribui um curso aleatório
      int opcaoCurso = distrib(gen);
      this->curso = static_cast<NomeCurso>(opcaoCurso); 
      return opcaoCurso;
   }

   // Método que retorna uma lista de nomes de alunos e seleciona um aleatoriamente
   vector<string> Aluno::ListNomesAlunos(){
      // Lista de nomes predefinidos
      vector<string> listNomesAlunos = { 
         "Ana Beatriz Ferreira", 
         "Mariana Oliveira", 
         "Pedro Henrique Santos", 
         "Camila Souza", 
         "Joao Victor Lima", 
         "Isabela Rocha", 
         "Rafael Costa", 
         "Larissa Nunes", 
         "Gabriel Martins"
      }; 
      
      // Seleção aleatória de um nome da lista
      random_device rd;
      mt19937 randomEngine(rd());
      uniform_int_distribution<size_t> dist(0, listNomesAlunos.size() - 1);
      size_t idx = dist(randomEngine);

      cout << "Nome: " << listNomesAlunos[idx] << endl;
      return listNomesAlunos;
   }

   // Método que retorna o nome do curso baseado no enum NomeCurso
   string Aluno::DefNomeCurso() const {
      // Switch case para converter o enum em string do nome do curso
      switch (this->curso){
      case NomeCurso:: A_INFORMATICA:
         return "Informatica";
      case NomeCurso:: A_QUIMICA:
         return "Quimica";
      case NomeCurso:: A_ADM:
         return "Administracao";
      case NomeCurso:: A_ADMSUB:
         return "Administracao (Subsequente)";
      case NomeCurso:: A_TADS:
         return "Análise e desenvolvimento de sistemas";
      case NomeCurso:: A_TPQ:
         return "Tecnologia em processos Quimicos";
      default:
         return "O curso nao faz parte do campus ou nao existe!";
      }
   }

   // Método que imprime todas as informações do aluno
   void Aluno::imprimirAluno(){
      cout << "Nome do aluno: " << nome << endl;
      cout << "Curso: " << DefNomeCurso() << endl;
      cout << "CPF: " << GerarCpf() << endl;
      cout << "Matricula: " << GerarNumMatricula() << endl;
      cout << endl;
   }
