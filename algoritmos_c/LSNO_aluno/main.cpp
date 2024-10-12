#include <iostream>
#define max 10

using namespace std;

struct Aluno{
    int matricula;
    string nome;
};

struct Lista{
    Aluno a[max];
    int tam; // tamanho
};

void iniciaLista(Lista *L){
    L->tam = 0;
}

bool listaC(Lista *L){    // lista cheia
    return L->tam == max;
}

bool listaV(Lista *L){
    return L->tam == 0;
}

int tamanho(Lista *L){
    return L->tam;
}

int posicao(Lista *L,int matr){
    int pos=0;
    while(pos<L->tam){
        if(L->a[pos].matricula == matr){
            return pos;                    // matricula existe na lista
        }else{
            pos++;                              
        }
    }
    return pos=-1;                         // matricula nao existe   
}

void inserir(Lista *L,string nome,int matr){
    int pos;
    if(!listaC(L)){
        pos = posicao(L,matr);
        if(pos<0){
            L->a[L->tam].nome = nome;
            L->a[L->tam].matricula = matr;
            L->tam++;
        }else{
            cout<<"\nO número de matrícula "<<matr<<" já existe na lista!\n";
        }
    }else{
        cout<<"\nA lista está cheia!\n";
    }
}

void deslocaEsqueda(Lista *L,int pos){
    while(pos < L->tam){
        L->a[pos] = L->a[pos+1];
        pos++;
    }
}

void remover(Lista *L,int matr){
    if(!listaV(L)){
        int pos = posicao(L,matr);
        if(pos > -1){
            deslocaEsqueda(L,pos);
            L->tam--;
            cout<<"\nAluno com a matrícula "<<matr<<" removido da lista!\n";
        }else{
            cout<<"\nO número de matrícula "<<matr<<" não existe na lista!\n";
        }
    }else{
        cout<<"A lista está vázia!";
    }
}

void imprimir(Lista *L){
    if(!listaV(L)){
        for(int cont=0;cont<L->tam;cont++){
            cout<<"Nome do aluno: "<<L->a[cont].nome<<endl;
            cout<<"Matrícula do aluno: "<<L->a[cont].matricula<<endl;
        }
    }else{
        cout<<"\nLista vazia!\n";
    }
}

Lista L;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    iniciaLista(&L);
    inserir(&L,"Anderson",4);
    inserir(&L,"Ana",1);
    inserir(&L,"Marcos",6);
    inserir(&L,"Anderson",7);
    inserir(&L,"Anderson",13);
    inserir(&L,"Anderson",0);
    inserir(&L,"Anderson",2);
    inserir(&L,"Anderson",5);
    inserir(&L,"Anderson",8);
    inserir(&L,"Anderson",9);
    inserir(&L,"Anderson",10);
    imprimir(&L);
    

    return 0;
}
