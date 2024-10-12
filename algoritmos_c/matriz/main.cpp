#include <iostream>

using namespace std;

int main()
{
    int valores[5][2], i, l, prod=1;
    
    cout<<"Digite 10 valores para a matriz: ";
    
    for(l=0;l<5;l++)
    {
        for(i=0;i<2;i++)
        {
            cin>>valores[l][i];
            if(valores[l][i]!=0)
            prod = prod * valores[l][i];
        }
    }
    
    for(l=0;l<5;l++)
    {
        for(i=0;i<2;i++)
        {
            cout<<valores[l][i];
        }
        cout<<endl;
    }
    
    cout<<"\nO resultado = "<<prod;
    
    return 0;
}