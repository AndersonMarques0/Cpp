#include <iostream>
#include <stdlib.h>
#define max 5

using namespace std;

struct aluno{
    int matricula;
    string nome;
};

struct Lista{
    aluno Fila[max];
    int total;
};

void iniciaFila(Lista *L){
    L->total = 0;
}

bool filaV(Lista *L){
    return L->total == 0;
}

bool filaC(Lista *L){
    return L->total == max;
}

aluno* criaItem(int mat,string nome){
    aluno* novo = new aluno;
    if(novo!=NULL){
        novo->matricula = mat;
        novo->nome = nome;
    }
    return novo;
}

void enfileirar(Lista *L,int mat,string nome){
    
    if(!filaC(L)){
        L->Fila[L->total].matricula = mat;
        L->Fila[L->total].nome = nome;
        L->total++;
    }
}

void deslocaEsquerda(Lista *L){
    for(int cont=0;cont<max;cont++){
        L->Fila[cont] = L->Fila[cont+1];
    }
}

aluno* desenfileirar(Lista *L){
    aluno* ret;
    if(!filaV(L)){
        ret = criaItem(L->Fila[0].matricula,L->Fila[0].nome);
        deslocaEsquerda(L);
        L->total--;
    }
    return ret;
}

void imprimir(Lista *L){
    if(!filaV(L)){
        cout<<"\n---------------------Imprimindo---------------------\n";
        for(int cont=0;cont<L->total;cont++){
            cout<<"Número de matrícula: "<<L->Fila[cont].matricula<<" - Nome do aluno: "<<L->Fila[cont].nome<<endl;
        }
    }
}


Lista L;
int main()
{
    
    setlocale(LC_ALL,"Portuguese");
    iniciaFila(&L);
    enfileirar(&L,3,"Anderson");
    enfileirar(&L,7,"Emanuel");
    enfileirar(&L,1,"Ana");
    imprimir(&L);
    desenfileirar(&L);
    cout<<"\nDesenfileirando uma vez\n";
    imprimir(&L);

    return 0;
}