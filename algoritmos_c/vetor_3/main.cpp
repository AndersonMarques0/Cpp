#include <iostream>

using namespace std;

int main()
{
    int vetor[20], i, media, soma=0, qtdd=0;
    
    cout<<"Digite 10 números: ";
    
    for(i=0;i<20;i++)
    {
        
        cin>>vetor[i];
        
        if(vetor[i]>9 && vetor[i]<26)
        {
            soma += vetor[i];
            qtdd++;
        }
        
    }
    
    media = soma/qtdd;
    
    cout<<"Este é a média dos valores que estão entre 10 e 25: "<<media<<endl;

    return 0;
}