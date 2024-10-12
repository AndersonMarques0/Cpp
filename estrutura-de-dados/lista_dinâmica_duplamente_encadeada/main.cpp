#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct Aluno {
    char nome[30];
    int matricula;
    Aluno* prox;
    Aluno* ant; // Ponteiro para o aluno anterior
};

struct Lista {
    int tam;
    Aluno* inicio;
};

void criarLista(Lista *L) {
    L->tam = 0;
    L->inicio = NULL;
}

void inserir(Lista *L, int matricula, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno != NULL) {
        novoAluno->matricula = matricula;
        strcpy(novoAluno->nome, nome);
        novoAluno->prox = NULL;
        novoAluno->ant = NULL; // Inicializa o ponteiro para o aluno anterior

        if (L->inicio == NULL || matricula < L->inicio->matricula) {
            // Inserir no início da lista
            novoAluno->prox = L->inicio;
            if (L->inicio != NULL) {
                L->inicio->ant = novoAluno; // Atualiza o ponteiro para o aluno anterior do aluno atual
            }
            L->inicio = novoAluno;
        } else {
            Aluno* atual = L->inicio;

            while (atual != NULL && matricula > atual->matricula) {
                atual = atual->prox;
            }

            if (atual == NULL || matricula != atual->matricula) {
                novoAluno->prox = atual;
                novoAluno->ant = atual->ant; // Atualiza o ponteiro para o aluno anterior do novo aluno
                if (atual != NULL) {
                    atual->ant = novoAluno; // Atualiza o ponteiro para o aluno anterior do aluno atual
                }
                if (novoAluno->ant != NULL) {
                    novoAluno->ant->prox = novoAluno; // Atualiza o ponteiro para o próximo aluno do aluno anterior
                }
            } else {
                cout << "A matrícula " << matricula << " já existe na lista. Não é possível adicionar novamente." << endl;
                free(novoAluno);
            }
        }

        L->tam++;
    } else {
        cout << "Erro na alocação de memória." << endl;
    }
}

void remover(Lista *L, int matricula) {
    Aluno* atual = L->inicio;
    bool encontrou = false;

    while (atual != NULL) {
        if (atual->matricula == matricula) {
            encontrou = true;
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox; // Atualiza o ponteiro para o próximo aluno do aluno anterior
            } else {
                // Remover o primeiro elemento
                L->inicio = atual->prox;
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant; // Atualiza o ponteiro para o aluno anterior do próximo aluno
            }
            free(atual);
            L->tam--;
            break;
        } else {
            atual = atual->prox;
        }
    }

    if (!encontrou) {
        cout << "Aluno com matrícula " << matricula << " não encontrado." << endl;
    }
}

void imprimirLista(Lista *L) {
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


int main()
{
    cout<<"Hello World";

    return 0;
}