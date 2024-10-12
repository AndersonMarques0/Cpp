#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    int MA;
    char tipo;
    char socio;
};

double calcularValor(Aluno aluno) {
    double valor;
    if (aluno.tipo == 'A' || aluno.tipo == 'a') {
        valor = 50;
    } else if (aluno.tipo == 'B' || aluno.tipo == 'b') {
        valor = 80;
    } else if (aluno.tipo == 'C' || aluno.tipo == 'c') {
        valor = 130;
    } else if (aluno.tipo == 'D' || aluno.tipo == 'd') {
        valor = 150;
    }

    if (aluno.socio == 'S' || aluno.socio == 's') {
        valor *= 0.5;
    }

    return valor;
}

int main() {
    Aluno alunos[60];
    int totalA = 0, totalB = 0, totalC = 0, totalD = 0, i = 0;
    double valor, total = 0;
    string continuar = "S";

    while (continuar == "S" || continuar == "s") {
        cout << "Digite a matrícula do aluno: ";
        cin >> alunos[i].MA;
        cout << "Digite o tipo de participação (A, B, C ou D): ";
        cin >> alunos[i].tipo;
        cout << "O aluno é sócio da SBC (S - sim ou N - não)? ";
        cin >> alunos[i].socio;

        if (alunos[i].tipo == 'A' || alunos[i].tipo == 'a') {
            totalA++;
        } else if (alunos[i].tipo == 'B' || alunos[i].tipo == 'b') {
            totalB++;
        } else if (alunos[i].tipo == 'C' || alunos[i].tipo == 'c') {
            totalC++;
        } else if (alunos[i].tipo == 'D' || alunos[i].tipo == 'd') {
            totalD++;
        }

        valor = calcularValor(alunos[i]);
        total += valor;

        cout << "O aluno de matrícula " << alunos[i].MA << " pagará R$" << valor << endl;

        cout << "Deseja continuar com o cadastro (S - sim ou N - não)? ";
        cin >> continuar;

        i++;
    }

    cout << "Total arrecadado com o evento: R$" << total << endl;
    cout << "Total de alunos matriculados em cada tipo de participação:" << endl;
    cout << "Tipo A: " << totalA << endl;
    cout << "Tipo B: " << totalB << endl;
    cout << "Tipo C: " << totalC << endl;
    cout << "Tipo D: " << totalD << endl;

    return 0;
}
