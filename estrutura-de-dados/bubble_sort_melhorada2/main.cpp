#include <iostream>

using namespace std;

int main()
{
    int vetor[5], n, i, aux, troca;
    
    for(i=0;i<5;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma decrescente
    // laço com a quantidade de elementos do vetor e enquanto houver troca
    n = 1;
    troca = 1;
    while(n<6 && troca == 1)
    {
        troca = 0;
        for(i=0;i<4;i++)
        {
            if(vetor[i]<vetor[i+1])
            {
                troca = 1;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
        n = n + 1;
    }
    // mostrando o vetor ordenando
    for(i=0;i<5;i++)
    {
        cout<<i+1<<"º numero: "<<vetor[i]<<"\n";
    }

    return 0;
}