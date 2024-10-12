#include <iostream>

using namespace std;

int main()
{
    int valor[10], produto[10], i, x;
    
    cout<<"Digite 10 valores: ";
    
    for(i=0;i<10;i++){
        
        cin>>valor[i];
        
        produto[i] = valor[i]*x;
    }
    
    cout<<"Digit e um número inteiro multiplicador: ";
    cin>>x;
    
    for(i=0;i<10;i++)
    {
        produto[i] = valor[i]*x;
    }
    
    cout<<endl;
    
    for(i=0;i<10;i++){
        
        cout<<produto[i]<<endl;
    }
    
    return 0;
}
