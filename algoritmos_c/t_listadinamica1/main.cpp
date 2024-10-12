#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Item{
    char nome[30];
    Item *prox;
};

struct Lista{
    Item *inicio;
};

void criaLista(Lista *L){
    L->inicio = NULL;
}

Item *criaItem(const char* nome){
    Item *I = (Item*)malloc(sizeof(Item));
    if(I!=NULL){
        strcpy(I->nome,nome);
        I->prox = NULL;
    }
    return I;
}

void inserir(Lista *L,const char* nome){
    Item *novo = criaItem(nome);
    if(novo!=NULL){
        novo->prox = L->inicio;
        L->inicio = novo;
    }
}

void remover(Lista *L,const char* nome){
    if(L->inicio!=NULL){
        Item *atual = L->inicio;
        Item *anterior = NULL;
        while(atual!=NULL){
            if(strcmp(atual->nome,nome) == 0){
                if(anterior==NULL){
                    L->inicio = atual->prox;
                }else{
                    anterior->prox = atual->prox;
                }
                free(atual);
                cout<<"\n"<<nome<<" removido\n\n";
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
}

void imprimir(Lista *L){
    if(L->inicio == NULL){
        cout<<"\nLista vázia!\n";
    }else{
        Item *atual = L->inicio;
        int i=1;
        while(atual!=NULL){
            cout<<"\nItem"<<i<<": "<<atual->nome<<endl;
            i++;
            atual = atual->prox;
        }
    }
        
}

int contarItens(Lista *L){
    Item *atual = L->inicio;
    int r;
    if(atual==NULL){
        r = 0;
    }else{
        int cont=0;
        while(atual!=NULL){
            cont++;
            atual = atual->prox;
        }
        r = cont;
    }
    return r;
}

void existeNome(Lista *L,const char* nome){
    Item *atual = L->inicio;
    if(atual==NULL){
        cout<<"Lista vázia!";
    }else{
        while(atual!=NULL){
            if(strcmp(atual->nome,nome) == 0){
                cout<<"O nome "<<nome<<" existe na lista.";
            }
            atual = atual->prox;
        }
    }
}

void removerTudo(Lista *L){
    if(L->inicio!=NULL){
        Item *atual = L->inicio;
        Item *anterior = NULL;
        while(atual!=NULL){
            if(anterior==NULL){
                anterior = atual;
                atual = atual->prox;
            }else{
                anterior = atual;
                atual = atual->prox;
            }
            free(atual);
        }
        cout<<"\nLista está limpa!\n";
        L->inicio=NULL;
    }
}

Lista L;
int tamanho;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    criaLista(&L);
    inserir(&L,"Anderson");
    inserir(&L,"Renata");
    inserir(&L,"Gabriel");
    inserir(&L,"Moana");
    imprimir(&L);
    removerTudo(&L);
    imprimir(&L);
    inserir(&L,"Anderson");
    imprimir(&L);
    return 0;
}
