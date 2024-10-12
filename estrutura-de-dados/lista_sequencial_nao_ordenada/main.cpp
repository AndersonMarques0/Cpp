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
    int i=0;
    while (i < L->tamanho) {
        if (L->a[i].matricula == matricula) {
            return i;
        }else{
            i++;
        }
    }
    return -1; // Matricula nao encontrada
}

void inserir(ListaAlunos *L,string nome,int matr) {
    int pos;
    if (!listaCheia(L)) {
        pos = posicao(L,matr);
        if(pos<0){
            L->a[L->tamanho].nome = nome;
            L->a[L->tamanho].matricula = matr;
            L->tamanho++;
        }else{
            cout << "A matrícula já existe!";
        }
    } else {
        cout << "A lista esta cheia!" << endl;
    }
}

void remover(ListaAlunos *L, int matricula) {
    int pos = posicao(L, matricula);
    if (pos > -1) {
        while (pos < L->tamanho - 1) {
            L->a[pos] = L->a[pos + 1];
            pos++;
        }
        L->tamanho--;
        cout << "Aluno com matricula " << matricula << " removido." << endl;
    } else {
        cout << "Aluno com matricula " << matricula << " nao encontrado." << endl;
    }
}

void imprimirLista(ListaAlunos *L) {
    if (listaVazia(L)) {
        cout << "A lista de alunos esta vazia." << endl;
    } else {
        cout << "Lista de Alunos:" << endl;
        for (int i = 0; i < L->tamanho; i++) {
            cout << "Matricula: " << L->a[i].matricula << " - Nome: " << L->a[i].nome << endl;
        }
    }
}

int main() {
    ListaAlunos L;
    criarLista(&L);

    int opcao;
    do {
        cout << "Escolha uma opcao:" << endl;
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
            cout << "Digite a matricula do aluno: ";
            cin >> cod;
            inserir(&L, nome, cod);
        } else if (opcao == 2) {
            int matricula;
            cout << "Digite a matricula do aluno a ser removido: ";
            cin >> matricula;
            remover(&L, matricula);
        } else if (opcao == 3) {
            imprimirLista(&L);
        }
    } while (opcao != 0);

    return 0;
}
