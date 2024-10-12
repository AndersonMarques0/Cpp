#include <iostream>

using namespace std;

int main()
{
    int vetor[5], i, j, eleito, menor, pos;
    
    // carregando os numeros no vetor
    for(i=0;i<5;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma crescente laço que percorre da 1ª posição à penúltima posição do vetor elegendo um
    // numero para ser comparado
    for(i=0;i<4;i++)
    {
        eleito = vetor[i];
        // encontrando o menor numero a direita do eleito com sua respectiva posicao
        // posicao do eleito = i
        // primeiro numero a direita do eleito na posicao = i + 1
        menor = vetor[i+1];
        pos = i+1;
        // laco que percorre os elementos que estao a direita do numero eleito, retornando o menor numero
        // a direita e sua posicao
        for(j=i+1;j<5;j++)
        {
            if(vetor[j]<menor)
            {
                menor = vetor[j];
                pos = j;
            }
        }
        if(menor<eleito)
        {
            vetor[i] = vetor[pos];
            vetor[pos] = eleito;
        }
    }
    // mostrando o vetor ordenando
    for(i=0;i<5;i++)
    {
        cout<<"\n"<<i+1<<"º numero: "<<vetor[i];
    }

    return 0;
}