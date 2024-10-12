#include <iostream>
#include <stdlib.h>

using namespace std;

struct aluno{
    string nome;
    int matricula;
    aluno *prox;
};

struct Fila{
    aluno *inicio;
    aluno *fim;
    int total;
};

void iniciaFila(Fila *F){
    F->inicio = NULL;
    F->fim = NULL;
    F->total = 0;
}

bool filaV(Fila *F){
    return F->inicio == NULL;
}

aluno *criaNo(int mat,string nome){
    aluno *novo;
    novo = new aluno;
    if(novo!=NULL){
        novo->nome = nome;
        novo->matricula = mat;
        novo->prox = NULL;
    }
    return novo;
}

void enfileirar(Fila *F,int mat,string nome){
    aluno *novo;
    novo = criaNo(mat,nome);
    if(novo!=NULL){
        if(filaV(F)){
            F->inicio = novo;
        }else{
            
            F->fim->prox = novo;
        }
        F->fim = novo;
        F->total++;
    }
        
}

aluno* desenfileirar(Fila *F){
    aluno *ret;
    
    if(filaV(F)){
        ret = NULL;
    }else{
        ret = F->inicio;
        F->inicio = F->inicio->prox;
        F->total--;
        if(filaV(F)){
            F->fim = F->inicio;
        }
    }
    return ret;
}

void imprimir(Fila *F){
    aluno *atual;
    cout<<"\n----------------------Imprimindo----------------------\n";
    for(atual=F->inicio;atual!=NULL;atual=atual->prox){
        cout<<"Número de matrícula: "<<atual->matricula<<" - Nome do aluno: "<<atual->nome<<endl;
    }
}

Fila F;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    iniciaFila(&F);
    enfileirar(&F,9,"Mariana");
    enfileirar(&F,5,"Bartolomeu");
    enfileirar(&F,13,"Vitória");
    imprimir(&F);
    cout<<"\nDesenfileirando uma vez.\n";
    desenfileirar(&F);
    imprimir(&F);

    return 0;
}