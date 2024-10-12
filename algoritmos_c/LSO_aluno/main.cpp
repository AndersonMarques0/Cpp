#include <iostream>
#define max 10

using namespace std;

struct Aluno{
    int matricula;
    string nome;
};

struct Lista{
    Aluno a[max];
    int tam;
};

void iniciaLista(Lista *L){
    L->tam = 0;
}

bool listaC(Lista *L){
    return L->tam == max;
}

bool listaV(Lista *L){
    return L->tam == 0;
}

int posicao(Lista *L,int matr){
    for(int pos=0;pos<L->tam;pos++){
        if(L->a[pos].matricula >= matr){
            return pos;
        }
    }
    return L->tam;
}

void deslocaDireita(Lista *L,int pos){
    for(int cont=L->tam;cont>pos;cont--){
        L->a[cont] = L->a[cont-1];
    }
}

void deslocaEsquerda(Lista *L,int pos){
    for(int cont=pos;cont<L->tam;cont++){
        L->a[cont] = L->a[cont+1];
    }
}


void inserir(Lista *L,string nome,int matr){
    int pos;
    if(!listaC(L)){
        pos = posicao(L,matr);
        if(pos < L->tam && matr == L->a[pos].matricula){
            cout<<"\nA matrícula "<<matr<<" já existe na lista!\n";
        }else{
            deslocaDireita(L,pos);
            L->a[pos].nome = nome;
            L->a[pos].matricula = matr;
            L->tam++;
        }
    }else{
        cout<<"\nA lista está cheia!\n";
    }
}

void remover(Lista *L,int matr){
    if(!listaV(L)){
        int pos = posicao(L,matr);
        deslocaEsquerda(L,pos);
        L->tam--;
        cout<<"\nNúmero de matrícula "<<matr<<" removido da lista!\n";
    }else{
        cout<<"\nA lista está vázia!\n";
    }
}

void imprimir(Lista *L){
    cout<<"\n----------------------Imprimindo----------------------\n";
    for(int cont=0;cont < L->tam;cont++){
        cout<<"Nome do aluno: "<<L->a[cont].nome<<endl;
        cout<<"Número de matrícula do aluno: "<<L->a[cont].matricula<<endl;
    }
}

Lista L;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    iniciaLista(&L);
    inserir(&L,"Anderson",5);
    inserir(&L,"Ana",3);
    inserir(&L,"Arthur",4);
    imprimir(&L);
    remover(&L,5);
    imprimir(&L);
    
    
    return 0;
}
