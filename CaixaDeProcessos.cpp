#include <iostream>
#include "CaixaDeProcessos.h"


using std::cout;

    CaixaDeProcessos::CaixaDeProcessos(){
        
    }

    void CaixaDeProcessos::empilhar( Processos *  novoProcesso){

        Node * novo = new Node; //cria um novo node(uma "caixinha") dentro da pilha
        novo->processo = novoProcesso; //coloca o novo processo dentro do node
        novo->proximo = top; //Faz o novo no apontar para o no que antes estava no topo da pilha.
        top = novo; //agora o top aponta para o novoProcesso

        //o processo de empilhar consiste em criar um novo espaco dentro da pilha

    }

     Processos*  CaixaDeProcessos::Desempilhar(){
        if (isEmpty()){               
            cout<< "A Caixa de processos está VAZIA!";
            return nullptr;
        }

        Node * temp = top; //Cria uma copia do no do topo em temp.
        Processos * elemento = temp->processo; 
        top = temp->proximo;
       delete temp; // 3. Libera a memória do "container" (o nó)

        return elemento;
    }

    bool CaixaDeProcessos::isEmpty(){
        return top == nullptr;
    }
