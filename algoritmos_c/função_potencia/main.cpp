#include <iostream>
#include<cmath>

using namespace std;

double potencia(double base, double expoente)
{
    double res;
    if(expoente==0)
    {
        res = 1;
    }
    else if(expoente==1)
    {
        res = base;
    }
    else if(expoente>0 && floor(expoente)==expoente)
    {
        res = base;
        for(int i=1;i<expoente;i++)
        {
            res *= base;
        }
    }
    else if(expoente<0)
    {
        res = 1/potencia(base,-expoente);
    }
    else
    {
        res = pow(base, expoente);
    }
    
    return res;
}

int main()
{
    double base;
    double expoente;
    
    cout<<"Este programa calcula a potencia do número digitado\n";
    cout<<"Digite a base seguido do expoente: ";
    cin>>base>>expoente;
    potencia(base,expoente);
    cout<<"O valor é "<<potencia(base,expoente)<<".";

    return 0;
}
