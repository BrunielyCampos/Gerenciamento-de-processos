// Inclusão das bibliotecas necessárias
#include <iostream>     // Para entrada/saída
#include <ctime>       // Para função time() usada na geração de números aleatórios
#include "Gerenciador.h" // Inclui a classe Gerenciador

using namespace std;

int main() {
    // Inicializa o gerador de números aleatórios com a hora atual como semente
    srand(time(NULL));

    // Imprime cabeçalho da simulação
    cout << "==========================================" << std::endl;
    cout << "  Iniciando Simulacao de Processos" << std::endl;
    cout << "==========================================" << std::endl;

    // Cria uma instância do Gerenciador
    Gerenciador sistema;

    // Inicia a simulação com 3 processos
    sistema.iniciarSimulacao(3);

    // Imprime rodapé indicando o fim da simulação
    cout << "\n==========================================" << std::endl;
    cout << "          Simulacao Finalizada" << std::endl;
    cout << "==========================================" << std::endl;

    // Retorna 0 indicando que o programa foi executado com sucesso
    return 0;
}