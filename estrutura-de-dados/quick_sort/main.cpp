#include <iostream>

using namespace std;

void troca(int vetor[],int i,int j)
{
    int aux;
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int particao(int vetor[],int p,int r)
{
    int pivo, i, j;
    pivo = vetor[(p+r)/2];
    i = p-1;
    j = r+1;
    while(i<j)
    {
        do
        {
            j = j - 1;    
        }while(vetor[j]>pivo);
        do
        {
            i = i + 1;
        }while(vetor[i]<pivo);
        if(i<j) troca(vetor,i,j);
    }
    return j;
}

void quicksort(int vetor[],int p,int r)
{
    int q;
    if(p<r)
    {
        q = particao(vetor,p,r);
        quicksort(vetor,p,q);
        quicksort(vetor,q+1,r);
    }
}

int main()
{
    int vetor[10];
    int i;
    // carregando os numeros do vetor
    for(i=0;i<10;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma crescente
    quicksort(vetor,0,9);
    //mostrando o vetor ordenando
    cout<<"Vetor ordenado";
    for(i=0;i<10;i++)
    {
        cout<<" "<<vetor[i];
    }
    
    
    return 0;
}