#include <iostream>

using namespace std;

int main()
{
    string nome[6], pesq, resp, x;
    int i, j, comeco, final, meio;
    bool acha;
    
    cout<<"Digite cinco nomes.\n";
    for(i=1;i<6;i++)
    {
        cin>>nome[i];
    }
    
    for(i=1;i<5;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(nome[i]>nome[j])
            {
                x = nome[i];
                nome[i] = nome[j];
                nome[j] = x;
            }
        }
    }
    
    resp="sim";
    while(resp=="sim")
    {
        cout<<"Digite o nome a ser pesquisado: ";
        cin>>pesq;
        comeco=1;
        final=5;
        acha=false;
        while(comeco<=final && acha==false)
        {
            meio = (comeco+final)/2;
            if(pesq==nome[meio])
            {
                acha=true;
            }else
            {
                if(pesq<nome[meio])
                {
                    final = meio - 1;
                }else
                {
                    comeco = meio + 1;
                }
            }
        }
        if(acha==true)
        {
            cout<<pesq<<" foi localizado na posição "<<meio<<".\n";
        }else
        {
            cout<<pesq<<" não foi localizado.";
        }
        cout<<"Deseja continuar?(sim/não): ";
        cin>>resp;
    }
    
    return 0;
}
