#include <iostream>

using namespace std;

int main()
{
    int vetor[5], n, i, aux;
    
    for(i=0;i<5;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma crescente
    // laço com a quantidade de elementos do vetor
    for(n=1;n<6;n++)
    {
        // laço que percorre da primeira à penúltima posição do vetor
        for(i=0;i<4;i++)
        {
            if(vetor[i]>vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
    // mostrando o vetor ordenando
    for(i=0;i<5;i++)
    {
        cout<<i+1<<"º numero: "<<vetor[i]<<"\n";
    }

    return 0;
}