#include <iostream>

using namespace std;

int main()
{
    int vetor[10], maior, menor, pmaior, pmenor, i;
    
    cout<<"Digite 10 números: ";
    
    for(i=0;i<10;i++)
    {
        cin>>vetor[i];
        
        if(i==0)
        {
            maior = vetor[i];
            menor = vetor[i];
        }else
        {
            if(vetor[i]>maior)
            {
                maior = vetor[i];
                pmaior = i;
            }
            
            if(vetor[i]<menor)
            {
                menor = vetor[i];
                pmenor = i;
            }
        }
    }
    
    cout<<"Este é o maior número: "<<maior<<endl;
    cout<<"Esta é a posição do maior número: "<<pmaior<<endl;
    cout<<"Este é o menor número: "<<menor<<endl;
    cout<<"Esta é a posição do menor número: "<<pmenor;
    

    return 0;
}