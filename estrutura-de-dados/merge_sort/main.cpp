#include <iostream>

using namespace std;

void intercala(int vetor[],int inicio,int fim,int meio)
    {
        int poslivre, inicio_vetor1, inicio_vetor2, i;
        int aux[10];
        inicio_vetor1 = inicio;
        inicio_vetor2 = meio+1;
        poslivre = inicio;
        
        while(inicio_vetor1<=meio && inicio_vetor2<=fim)
        {
            if(vetor[inicio_vetor1]<=vetor[inicio_vetor2])
            {
                aux[poslivre] = vetor[inicio_vetor1];
                inicio_vetor1 = inicio_vetor1 + 1;
            }else
            {
                aux[poslivre] = vetor[inicio_vetor2];
                inicio_vetor2 = inicio_vetor2 + 1;
            }
            poslivre = poslivre + 1;
        }
        // se ainda existem numeros no primeiro vetor que nao foram intercalados
        for(i=inicio_vetor1;i<=meio;i++)
        {
            aux[poslivre] = vetor[i];
            poslivre = poslivre + 1;
        }
        // se ainda existem numeros no segundo vetor que nao foram intercalados
        for(i=inicio_vetor2;i<=fim;i++)
        {
            aux[poslivre] = vetor[i];
            poslivre = poslivre + 1;
        }
        // retorna os valores do vetor aux para o vetor vetor
        for(i=inicio;i<=fim;i++)
        {
            vetor[i] = aux[i];
        }
    }
    
    void merge(int vetor[], int inicio, int fim)
    {
        int meio;
        if(inicio<fim)
        {
            meio = (inicio+fim)/2;
            merge(vetor,inicio,meio);
            merge(vetor,meio+1,fim);
            intercala(vetor,inicio,fim,meio);
        }
    }

int main()
{
    int vetor[10];
    int i;
    // carregando os numeros no vetor
    for(i=0;i<10;i++)
    {
        cout<<"Digite o "<<i+1<<"º numero: ";
        cin>>vetor[i];
    }
    // ordenando de forma crescente
    merge(vetor,0,9);
    // mostrando o vetor ordenando
    for(i=0;i<10;i++)
    {
        cout<<"\n"<<i+1<<"º numero: "<<vetor[i];
    }
    

    return 0;
}