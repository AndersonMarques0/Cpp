#include <iostream>

using namespace std;

int main()
{
    string nome[5], pesq, resp;
    bool acha;
    int i;
    
    cout<<"Digite 5 nomes.\n";
    for(int i=0;i<5;i++)
    {
        cin>>nome[i];
    }
    
    resp="sim";
    while(resp=="sim")
    {
        cout<<"Entre o nome a ser pesquisado: ";
        cin>>pesq;
        i=0;
        acha = false;
        while(i<=5 && acha==false)
        {
            if(pesq==nome[i])
            {
                acha = true;
            }else
            {
                i++;
            }
        }
        if(acha==true)
        {
            cout<<"O nome digitado foi localizada na posição "<<i<<".\n";
        }else
        {
            cout<<"Não foi localizado.";
        }
        cout<<"Deseja continuar?(sim/não): ";
        cin>>resp;
    }
    
    return 0;
}