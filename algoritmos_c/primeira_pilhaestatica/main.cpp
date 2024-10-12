#include <iostream>
#define max 10

using namespace std;

struct item{
   int num;
};

struct Pilha{
    item Lista[max];
    int topo;
};

void iniciaPilha(Pilha *P){
    P->topo = -1;
}

bool pilhaV(Pilha *P){
    return P->topo == -1;
}

int tamanho(Pilha *P){
    return P->topo + 1;
}

bool pilhaC(Pilha *P){
    return P->topo == max;
}

void empilha(Pilha *P,int dado){
    
    if(!pilhaC(P)){
        P->topo++;
        P->Lista[P->topo].num = dado;
    }
}

item* desempilha(Pilha *P){
    item *ret = NULL;
    if(!pilhaV(P)){
        ret = &(P->Lista[P->topo]);
        P->topo--;
    }
    return ret;
}

void imprimir(Pilha *P){
    
    cout<<"\n-------------------Imprimindo Pilha-------------------\n";
    for(int cont=P->topo;cont>=0;cont--){
        cout<<P->Lista[cont].num<<", ";
    }
}


Pilha P;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    iniciaPilha(&P);
    empilha(&P,4);
    empilha(&P,2);
    empilha(&P,7);
    imprimir(&P);
    int t = tamanho(&P);
    cout<<"\nTamanho da Pilha: "<<t;
    desempilha(&P);
    cout<<"\nDesempilhando uma vez.\n";
    imprimir(&P);

    return 0;
}