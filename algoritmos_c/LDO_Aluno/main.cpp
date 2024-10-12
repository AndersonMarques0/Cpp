#include <iostream>
#include <cstring>

using namespace std;

struct Aluno{
    char nome[30];
    int matricula;
    Aluno *prox;
};

struct Lista{
    Aluno *inicio;
};

void iniciaLista(Lista *L){
    L->inicio = NULL;
}

Aluno* criaNo(const char* nome,int matr){
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo!=NULL){
        strcpy(novo->nome,nome);
        novo->matricula = matr;
        novo->prox = NULL;
    }
    return novo;
}

void inserir(Lista *L,const char* nome,int matr){
    Aluno *novo = criaNo(nome,matr);
    if(novo!=NULL){
        if(L->inicio == NULL || matr < L->inicio->matricula){
            novo->prox = L->inicio;
            L->inicio = novo;
        }else{
            Aluno *anterior = NULL;
            Aluno *atual = L->inicio;
            while(atual!=NULL && matr > atual->matricula){
                anterior = atual;
                atual = atual->prox;
            }
            
            if(atual==NULL || matr != atual->matricula){
                if(anterior!=NULL){
                    anterior->prox = novo;
                }
                novo->prox = atual;
            }else{
                cout<<"O número de matrícula "<<matr<<" já existe";
            }
              
        }
    }
}

void remover(Lista *L,int matr){
    Aluno *atual = L->inicio;
    Aluno *anterior = NULL;
    while(atual!=NULL){
        if(atual->matricula == matr){
            if(anterior==NULL){
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
    cout<<"\n-----------------Imprimindo-----------------\n";
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
    inserir(&L,"Anderson",5);
    inserir(&L,"Ana",2);
    inserir(&L,"Arthur",3);
    inserir(&L,"Beatriz",6);
    imprimir(&L);
    remover(&L,3);
    imprimir(&L);

    return 0;
}