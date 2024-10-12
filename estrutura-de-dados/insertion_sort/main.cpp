#include <iostream>

using namespace std;

int main()
{
    int vetor[5];
    int i, j, eleito;
    // carregando os numeros no vetor
    for(i=0;i<5;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma crescente
    // laço com a quantidade de elementos do vetor - 1
    for(i=1;i<5;i++)
    {
        eleito = vetor[i];
        j = i - 1;
        // laço que percorre os elementos a esquerda do numero eleito ou até encontrar a posição para
        // recolocação do número eleito respeitando a ordenação procurada
        while(j>=0 && vetor[j]>eleito)
        {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = eleito;
    }
    // mostrando o vetor ordenando
    for(i=0;i<5;i++)
    {
        cout<<"\n"<<i+1<<"º numero: "<<vetor[i];
    }
    
    return 0;
}