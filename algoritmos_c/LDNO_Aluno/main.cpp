#include <iostream>
#include <cstring>

using namespace std;

struct Aluno{
    int matricula;
    char nome[30];
    Aluno *prox;
};

struct Lista{
    Aluno *inicio;
};

void iniciaLista(Lista *L){
    L->inicio = NULL;
}

bool listaV(Lista *L){
    return L->inicio == NULL;
}

Aluno* criaNo(int matr,const char* nome){
    Aluno *novo;
    novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo!=NULL){
        strcpy(novo->nome,nome);
        novo->matricula = matr;
        novo->prox = NULL;
    }
    return novo;
}

void inserir(Lista *L,int matr,const char* nome){
    Aluno *novo = criaNo(matr,nome);
    if(novo!=NULL){
        novo->prox = L->inicio;
        L->inicio = novo;
    }
}

void remover(Lista *L,int matr){
    Aluno *anterior = NULL, *atual = L->inicio;
    while(atual!=NULL){
        if(matr == atual->matricula){
            if(anterior == NULL){
                L->inicio = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }
            free(atual);
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void imprimir(Lista *L){
    Aluno *atual = L->inicio;
    cout<<"\n-------------------Imprimindo-------------------\n";
    while(atual!=NULL){
        cout<<"Número de matrícula: "<<atual->matricula<<" - "<<"Nome do aluno: "<<atual->nome<<endl;
        atual = atual->prox;
    }
}

Lista L;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    iniciaLista(&L);
    inserir(&L,1,"Anderson");
    inserir(&L,2,"Ana Vitória");
    inserir(&L,3,"Ana beatriz");
    imprimir(&L);
    remover(&L,1);
    imprimir(&L);

    return 0;
}