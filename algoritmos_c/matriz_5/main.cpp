#include <iostream>

using namespace std;

int main()
{
    int matriz1[6][4], matriz2[6][4], l, c, cont;
    
    cout<<"Digite os valores da primeira matriz: ";
    
    for(l=0;l<6;l++)
    {
        for(c=0;c<4;c++)
        {
            cin>>matriz1[l][c];
        }
    }
    
    for(l=0;l<6;l++)
    {
        for(c=0;c<4;c++)
        {
            if(matriz1[l][c]>30)
            {
                cont++;
            }
            if(matriz1[l][c]==0)
            {
                matriz2[l][c] = 0;
            }else{
                    matriz2[l][c] = matriz1[l][c];
                }
            
        }
    }
    
    cout<<"Quantidade de valores maiores que 30: "<<cont<<endl;
    
    cout<<"Valores da segunda matriz: ";
    for(l=0;l<6;l++)
    {
        cout<<endl;
        for(c=0;c<4;c++)
        {
            cout<<matriz2[l][c]<<" | ";
        }
    }
    
    
    return 0;
}