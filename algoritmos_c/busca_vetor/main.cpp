#include <iostream>

using namespace std;

int main()
{
    
    double vetor[8], num, pos=8;
    int i=0;
    
    cout<<"Digite oito números: ";
    for(i=0;i<8;i++)
    {
        cin>>vetor[i];
    }
    
    cout<<"Digite outro número: ";
    cin>>num;
    
    for(i=0;i<8;i++)
    {
        if(vetor[i]==num)
        {
            
            pos = i;
            break;
        }
        
    }
    
    if(pos<8)
    {
        cout<<"O número digitado existe no vetor.\n";
        cout<<"Está na posição "<<pos<<".";
    }else
    {
        cout<<"O número digitado não existe no vetor";
    }

    return 0;
}
