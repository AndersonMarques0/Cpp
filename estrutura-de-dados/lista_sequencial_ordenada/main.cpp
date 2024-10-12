#include <iostream>
#include <string>
#define MAX 10

using namespace std;

struct Aluno {
    string nome;
    int matricula;
};

struct ListaAlunos {
    Aluno a[MAX];
    int tamanho;
};

void criarLista(ListaAlunos *L) {
    L->tamanho = 0;
}

bool listaCheia(ListaAlunos *L) {
    return L->tamanho == MAX;
}

bool listaVazia(ListaAlunos *L) {
    return L->tamanho == 0;
}

int tamanhodaLista(ListaAlunos *L) {
    return L->tamanho;
}

int posicao(ListaAlunos *L, int matricula) {
    for (int i = 0; i < L->tamanho; i++) {
        if (L->a[i].matricula >= matricula) {
            return i;
        }
    }
    return L->tamanho;
}

void deslocaDireita(ListaAlunos *L, int pos) {
    for (int i = L->tamanho; i > pos; i--) {
        L->a[i] = L->a[i - 1];
    }
}

void inserir(ListaAlunos *L, string nome, int matr) {
    if (!listaCheia(L)) {
        int pos = posicao(L, matr);
        if (pos < L->tamanho && L->a[pos].matricula == matr) {
            cout << "A matrícula já existe!";
        } else {
            deslocaDireita(L, pos);
            L->a[pos].nome = nome;
            L->a[pos].matricula = matr;
            L->tamanho++;
        }
    } else {
        cout << "A lista está cheia!" << endl;
    }
}

void remover(ListaAlunos *L, int matricula) {
    int pos = posicao(L, matricula);
    if (pos < L->tamanho && L->a[pos].matricula == matricula) {
        while (pos < L->tamanho - 1) {
            L->a[pos] = L->a[pos + 1];
            pos++;
        }
        L->tamanho--;
        cout << "Aluno com matrícula " << matricula << " removido." << endl;
    } else {
        cout << "Aluno com matrícula " << matricula << " não encontrado." << endl;
    }
}

void imprimirLista(ListaAlunos *L) {
    if (listaVazia(L)) {
        cout << "A lista de alunos está vazia." << endl;
    } else {
        cout << "Lista de Alunos:" << endl;
        for (int i = 0; i < L->tamanho; i++) {
            cout << "Matrícula: " << L->a[i].matricula << " - Nome: " << L->a[i].nome << endl;
        }
    }
}

int main() {
    ListaAlunos L;
    criarLista(&L);

    int opcao;
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Remover aluno" << endl;
        cout << "3 - Imprimir lista de alunos" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        if (opcao == 1) {
            Aluno a;
            string nome;
            int cod;
            cout << "Digite o nome do aluno: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite a matrícula do aluno: ";
            cin >> cod;
            inserir(&L, nome, cod);
        } else if (opcao == 2) {
            int matricula;
            cout << "Digite a matrícula do aluno a ser removido: ";
            cin >> matricula;
            remover(&L, matricula);
        } else if (opcao == 3) {
            imprimirLista(&L);
        }
    } while (opcao != 0);

    return 0;
}