#include <iostream>

using namespace std;

int main()
{
    int vetor1[5], vetor2[5], vetor3[10], i, l, a=1;
    
    cout<<"Digite 5 números: ";
    
    for(i=0;i<5;i++)
    {
        cin>>vetor1[i];
    }
    
    cout<<"Digite outros 5 números: ";

    for(i=0;i<5;i++)
    {
        cin>>vetor2[i];
    }
    
    for(i=0;i<5;i++)
    {
        vetor3[l] = vetor1[i];
        l += 2;
        if(l>10)
        {
            break;
        }
    }
    
    for(i=0;i<5;i++)
    {
        
        vetor3[a] = vetor2[i];
        a += 2;
        if(a>10)
        {
            break;
        }
    }
    
    cout<<"Este são os números reorganizados em intercalação: "<<endl;
    
    for(i=0;i<10;i++)
    {
        cout<<vetor3[i]<<" | ";
    }

    return 0;
}
