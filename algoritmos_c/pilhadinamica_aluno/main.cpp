#include <iostream>

using namespace std;

struct aluno{
    int matricula;
    string nome;
    aluno *prox;
};

struct Pilha{
    aluno *topo;
    int total;
};

void iniciaPilha(Pilha *P){
    P->topo = NULL;
    P->total = 0;
}

bool pilhaV(Pilha *P){
    return P->topo == NULL;
}

aluno *criarAluno(int mat,string nome){
    aluno *novo;
    novo = new aluno;
    if(novo!=NULL){
        novo->matricula = mat;
        novo->nome = nome;
    }
    return novo;
}

void empilhar(Pilha *P,int mat,string nome){
    aluno *novo;
    novo = criarAluno(mat,nome);
    if(novo!=NULL){
        novo->prox = P->topo;
        P->topo = novo;
        P->total++;
    }
}

aluno* desempilhar(Pilha *P){
    aluno *ret = NULL;
    if(!pilhaV(P)){
        ret = P->topo;
        P->topo = P->topo->prox;
        P->total--;
    }
    return ret;
}

void imprimir(Pilha *P){
    aluno *cont;
    cout<<"\n----------------Imprimindo alunos cadastrados----------------\n";
    for(cont=P->topo;cont!=NULL;cont=cont->prox){
        cout<<"Número de matrícula: "<<cont->matricula<<" - Nome do aluno: "<<cont->nome<<endl;
    }
}

Pilha P;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    iniciaPilha(&P);
    empilhar(&P,3,"Anderson");
    empilhar(&P,1,"Ana");
    empilhar(&P,5,"Arthur");
    imprimir(&P);
    cout<<"\nDesempilhando duas vezes.\n";
    desempilhar(&P);
    desempilhar(&P);
    imprimir(&P);

    return 0;
}
