#include <iostream>
#include "CaixaDeProcessos.h"
#include "Processos.h"


using std::cout;

    CaixaDeProcessos::CaixaDeProcessos(){
        
    }

    void CaixaDeProcessos::empilhar(TipoProcesso novoProcesso){

        Node * novo = new Node; //cria um novo node(uma "caixinha") dentro da pilha
        novo->processo = novoProcesso; //coloca o novo processo dentro do node
        novo->proximo = top; //Faz o novo nó apontar para o nó que antes estava no topo da pilha.
        top = novo; //agora o top aponta para o novoProcesso

        //o processo de empilhar consiste em criar um novo espaco dentro da pilha

    }

    void CaixaDeProcessos::Desempilhar(void (*DistribuirPrioridade)(TipoProcesso)){
        if (isEmpty()){               
            cout<< "A Caixa de processos está VAZIA!";
            return;
        }

        Node * temp = top; //Cria uma cópia do nó do topo em temp.
        TipoProcesso elemento = temp->processo; 
        top = temp->proximo;
        delete temp;
        DistribuirPrioridade(elemento);
        temp = nullptr;
    }

    bool CaixaDeProcessos::isEmpty(){
        return top == nullptr;
    }
