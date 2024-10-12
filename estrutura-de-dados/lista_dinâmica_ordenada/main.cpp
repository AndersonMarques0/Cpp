#include <iostream>
#include <cstring>
#include <stdlib.h>

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

void inserir(Lista *L, int matricula, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno != NULL) {
        novoAluno->matricula = matricula;
        strcpy(novoAluno->nome, nome);
        novoAluno->prox = NULL;

        if (L->inicio == NULL || matricula < L->inicio->matricula) {
            // Inserir no início da lista
            novoAluno->prox = L->inicio;
            L->inicio = novoAluno;
        } else {
            Aluno* atual = L->inicio;
            Aluno* anterior = NULL;

            while (atual != NULL && matricula > atual->matricula) {
                anterior = atual;
                atual = atual->prox;
            }

            if (atual == NULL || matricula != atual->matricula) {
                if (anterior != NULL) {
                    anterior->prox = novoAluno;
                }
                novoAluno->prox = atual;
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

void inserirRecursivo(Aluno** atual, int matricula, const char* nome) {
    if (*atual == NULL || matricula < (*atual)->matricula) {
        Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
        if (novoAluno != NULL) {
            novoAluno->matricula = matricula;
            strcpy(novoAluno->nome, nome);
            novoAluno->prox = *atual;
            *atual = novoAluno;
        } else {
            cout << "Erro na alocação de memória." << endl;
        }
    } else if (matricula > (*atual)->matricula) {
        inserirRecursivo(&((*atual)->prox), matricula, nome);
    } else {
        cout << "A matrícula " << matricula << " já existe na lista. Não é possível adicionar novamente." << endl;
    }
}

void inserir(Lista *L, int matricula, const char* nome) {
    inserirRecursivo(&(L->inicio), matricula, nome);
    L->tam++;
}


void remover(Lista *L, int matricula) {
    Aluno* atual = L->inicio;
    Aluno* anterior = NULL;
    bool encontrou = false;

    while (atual != NULL) {
        if (atual->matricula == matricula) {
            encontrou = true;
            if (anterior == NULL) {
                // Remover o primeiro elemento
                L->inicio = atual->prox;
                free(atual);
                L->tam--;
                atual = L->inicio; // Continue a partir do próximo elemento
            } else {
                anterior->prox = atual->prox;
                free(atual);
                L->tam--;
                atual = anterior->prox; // Continue a partir do próximo elemento
            }
        } else {
            anterior = atual;
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

int main() {
    setlocale(LC_ALL,"Portuguese");
    Lista L;
    criarLista(&L);

    inserir(&L, 2, "Aluno 2");
    inserir(&L, 1, "Aluno 1");
    inserir(&L, 3, "Aluno 3");

    cout << "Lista após inserção:" << endl;
    imprimirLista(&L);

    remover(&L, 1);
    

    cout << "Lista após remoção:" << endl;
    imprimirLista(&L);

    return 0;
}