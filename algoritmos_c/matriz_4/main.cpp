#include <iostream>

using namespace std;

int main()
{
    int matriz[8][6], l, c, soma=0, cont=0;
    float media;
    
    cout<<"Digite os valores: ";
    
    for(l=0;l<8;l++)
    {
        for(c=0;c<6;c++)
        {
            cin>>matriz[l][c];
            
            if(l!=0)
            {
                if(l%2==0)
                {
                    soma = soma + matriz[l][c];
                    cont++;
                } 
            }
            
        }
    }
    
    media = soma/cont;
    
    cout<<"Média dos valores das linhas pares: "<<media;

    return 0;
}