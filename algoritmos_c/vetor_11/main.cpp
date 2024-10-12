#include <iostream>

using namespace std;

int main()
{
    int vetor[10], i;
    
    
    for(i=1;i<10;i++)
    {
        if(i%2==0)
        {
            vetor[i] = 0;
        }else
        {
            vetor[i] = 1;
        }
            
    }
    
    for(i=0;i<10;i++)
    {
        cout<<vetor[i]<<" | ";
    }

    return 0;
}