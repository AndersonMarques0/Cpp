#include <iostream>
#include <cstring>


using namespace std;

struct Aluno {
    char nome[30];
    int matricula;
    Aluno* prox;
};

struct Lista {
    int tam;
    Aluno* inicio;
};

void criarLista(Lista *L) {
    L->tam = 0;
    L->inicio = NULL;
}

bool lVazia(Lista *L){
    return L->tam == 0;
}

int tamanho(Lista *L){
    return L->tam;
}

Aluno *criarElemento(int matr,const char* nome){
    Aluno *a = (Aluno*)malloc(sizeof(Aluno));
    if (a != NULL) {
        strcpy(a->nome, nome);
        a->matricula = matr;
        a->prox = NULL;
    }
    return a;
}

void inserir(Lista *L, int matricula, const char* nome) {
    // Verifica se a matrícula já existe
    Aluno* atual = L->inicio;
    while (atual != NULL) {
        if (atual->matricula == matricula) {
            cout << "A matrícula " << matricula << " já existe na lista. Não é possível adicionar novamente." << endl;
            return;
        }
        atual = atual->prox;
    }

    Aluno* novoAluno = criarElemento(matricula, nome);
    if (novoAluno != NULL) {
        novoAluno->prox = L->inicio;
        L->inicio = novoAluno;
        L->tam++;
    }
}

void remover(Lista *L, int matricula) {
    Aluno* atual = L->inicio;
    Aluno* anterior = NULL;

    while (atual != NULL) {
        if (atual->matricula == matricula) {
            if (anterior == NULL) {
                L->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            L->tam--;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void imprimir(Lista *L) {
    Aluno* atual = L->inicio;

    if (atual == NULL) {
        cout << "A lista de alunos está vazia." << endl;
    } else {
        cout << "Lista de Alunos:" << endl;
        while (atual != NULL) {
            cout << "Matrícula: " << atual->matricula << " - Nome: " << atual->nome << endl;
            atual = atual->prox;
        }
    }
}

int main() {
    Lista L;
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
            int matricula;
            char nome[30];
            cout << "Digite a matrícula do aluno: ";
            cin >> matricula;
            cout << "Digite o nome do aluno: ";
            cin.ignore();
            cin.getline(nome, 30);
            inserir(&L, matricula, nome);
        } else if (opcao == 2) {
            int matricula;
            cout << "Digite a matrícula do aluno a ser removido: ";
            cin >> matricula;
            remover(&L, matricula);
        } else if (opcao == 3) {
            imprimir(&L);
        }
    } while (opcao != 0);

    // Liberar a memória alocada para a lista
    Aluno* atual = L.inicio;
    while (atual != NULL) {
        Aluno* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}

