#include <iostream>

int main() {
    const int tamanhoTurma = 5;
    int codigo, sexo;
    double altura, maiorAltura, menorAltura, somaAlturaMulheres = 0.0, somaAlturaTurma = 0.0;
    int contadorMulheres = 0;

    // Inicializar as alturas com valores inválidos para serem substituídos durante a leitura
    maiorAltura = menorAltura = -1.0;

    for (int i = 1; i <= tamanhoTurma; ++i) {
        std::cout << "Informe a altura (em metros) da pessoa " << i << ": ";
        std::cin >> altura;

        std::cout << "Informe o sexo (1 - masculino, 2 - feminino) da pessoa " << i << ": ";
        std::cin >> sexo;

        // Verificar se a altura é a maior ou a menor da turma
        if (altura > maiorAltura || maiorAltura == -1.0) {
            maiorAltura = altura;
        }

        if (altura < menorAltura || menorAltura == -1.0) {
            menorAltura = altura;
        }

        // Verificar o sexo e atualizar as somas das alturas
        if (sexo == 2) { // Código 2 representa o sexo feminino
            somaAlturaMulheres += altura;
            contadorMulheres++;
        }

        somaAlturaTurma += altura;
    }

    // Calcular média da altura das mulheres
    double mediaAlturaMulheres = somaAlturaMulheres / contadorMulheres;

    // Calcular média da altura da turma
    double mediaAlturaTurma = somaAlturaTurma / tamanhoTurma;

    // Mostrar resultados
    std::cout << "Maior altura da turma: " << maiorAltura << " metros" << std::endl;
    std::cout << "Menor altura da turma: " << menorAltura << " metros" << std::endl;
    std::cout << "Média da altura das mulheres: " << mediaAlturaMulheres << " metros" << std::endl;
    std::cout << "Média da altura da turma: " << mediaAlturaTurma << " metros" << std::endl;

    return 0;
}