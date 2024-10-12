#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int num;
    std::cout << "Digite um número entre 3 e 18: ";
    std::cin >> num;

    if (num < 3 || num > 18) {
        std::cout << "Número inválido. Deve ser entre 3 e 18.\n";
        return 0;
    }

    int totalPossibilidades = 0;
    int possibilidadesFavoraveis = 0;

    // Calcula todas as possibilidades de jogar três dados
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                totalPossibilidades++;
                if (i + j + k == num) {
                    possibilidadesFavoraveis++;
                }
            }
        }
    }

    double probabilidade = (double)possibilidadesFavoraveis / totalPossibilidades * 100;
    std::cout << "A probabilidade de obter " << num << " ao jogar três dados é " << 
    setprecision(3) << probabilidade << "%.\n";

    return 0;
}
