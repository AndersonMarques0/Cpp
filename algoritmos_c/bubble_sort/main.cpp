#include <iostream>

using namespace std;

int main()
{
    string vetor[5], x;
    int i,j;
    
    cout<<"Este programa apresenta os nomes em ordem alfabética.\n";
    cout<<"Digite cinco nomes.\n";
    for(i=0;i<5;i++)
    {
        cin>>vetor[i];
    }
    
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(vetor[i]>vetor[j])
            {
                x = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = x;
            }
        }
    }
    
    for(i=0;i<5;i++)
    {
        cout<<vetor[i]<<" | ";
    }

    return 0;
}