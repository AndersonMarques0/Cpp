#include <iostream>

using namespace std;

int main()
{
    int vetor[5], j, i, aux;
    
    // carregando os numeros do vetor
    for(i=0;i<5;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma crescente
    // laço com a quantidade de elementos do vetor -1
    for(j=1;j<5;j++)
    {
        // laço que percorre da última a posição j do vetor
        for(i=4;i>=j;i--)
        {
            if(vetor[i]<vetor[i-1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i-1];
                vetor[i-1] = aux;
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