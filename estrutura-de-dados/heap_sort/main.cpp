#include <iostream>

using namespace std;

int vetor[11];

void heap_fica(int i,int qtde)
{
    int f_esq,f_dir, maior, aux;
    maior = i;
    if(2*i+1<=qtde)
    {
        // no que esta sendo analisado tem filhos para esquerda e direita
        f_esq = 2*i+1;
        f_dir = 2*i;
        if(vetor[f_esq]>=vetor[f_dir] && vetor[f_esq]>vetor[i])
        {
            maior = 2*i+1;
        }else if(vetor[f_dir]>vetor[f_esq] && vetor[f_dir] > vetor[i])
        {
            maior = 2*i;
        }else if(2*i<=qtde)
        {
            // no que esta sendo analisado tem filho apenas para a direita
            f_dir = 2*i;
            if(vetor[f_dir]>vetor[i])
            {
                maior = 2*i;
            }
        }
        if(maior!=i)
        {
            aux = vetor[i];
            vetor[i] = vetor[maior];
            vetor[maior] = aux;
            heap_fica(maior,qtde);
        }
    }
}

void transforma_heap(int qtde)
{
    int i, pai, aux;
    for(i=qtde/2;i>=1;i--)
    {
        heap_fica(i,qtde);
    }
}

void ordena(int qtde)
{
    int i, aux, ultima_posi;
    for(i=qtde;i>=2;i--)
    {
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        ultima_posi = i - 1;
        heap_fica(1,ultima_posi);
    }
}

int main()
{
    int i,qtde;
    
    // carregando os numeros no vetor
    for(i=1;i<11;i++)
    {
        cout<<"Digite o "<<i<<"º numero: ";
        cin>>vetor[i];
    }
    
    // transforma o vetor digitado em um heap cada no pai e maior que seus filhos
    qtde=10;
    transforma_heap(qtde);
    // ordenando de forma crescente
    ordena(qtde);
    // mostrando o vetor ordenando
    for(i=1;i<11;i++)
    {
        cout<<"\n"<<i<<"º numero: "<<vetor[i];
    }

    return 0;
}
