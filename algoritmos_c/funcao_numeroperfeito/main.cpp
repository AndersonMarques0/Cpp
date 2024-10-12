#include <iostream>

using namespace std;

void perfectNumber(int a)
{
    int soma=0;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0)
        {
            soma = soma + i;
            if(soma==a)
            {
                cout<<"O numero digitado e perfeito.";
                break;
            }
        }
        if(i==a)
        {
            cout<<"O numero digitado nao e perfeito.";
        }
    }
}

int main()
{
    
    int number;
    cout<<"Este programa calcula o numero perfeito.\n";
    cout<<"Digite o numero: ";
    cin>>number;
    perfectNumber(number);

    return 0;
}