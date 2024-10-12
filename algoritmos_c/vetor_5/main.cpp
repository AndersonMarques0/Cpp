#include <iostream>

using namespace std;

int main()
{
    int vetor[6], par=0, impar=0, i;
    
    cout<<"Digite 6 números: ";
    
    for(i=0;i<6;i++)
    {
        cin>>vetor[i];
        
        if(vetor[i]%2==0)
        {
          par++; 
        }else
        {
            impar++;
        }
        
    }
    
    cout<<"Quantidade de números pares: "<<par<<endl;
    cout<<"\t";
    
    for(i=0;i<6;i++)
    {
        if(vetor[i]%2==0)
        {
            cout<<vetor[i]<<" | ";
        }
        
    }
    
    
    cout<<endl;
    cout<<"Quantidade de números ímpares: "<<impar<<endl;
    cout<<"\t";
    
    for(i=0;i<6;i++)
    {
        if(vetor[i]%2!=0)
        {
            cout<<vetor[i]<<" | ";
        }
        
    }

    return 0;
}