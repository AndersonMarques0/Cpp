#include <iostream>
#include <cmath>

using namespace std;

double potencia(double base, double expoente)
{
    double resultado;
    if(expoente == 0)
    {
        resultado = 1;
    }
    else if(expoente == 1)
    {
        resultado = base;
    }
    else if(expoente > 0 && floor(expoente) == expoente)
    {
        resultado = base;
        for(int i = 1; i < expoente; i++)
        {
            resultado *= base;
        }
    }
    else if(expoente < 0)
    {
        resultado = 1 / potencia(base, -expoente);
    }
    else
    {
        resultado = pow(base, expoente);
    }
    
    return resultado;
}

int main()
{
    double base, expoente;
    
    cout << "Este programa calcula a potência do número digitado.\n";
    
    cout << "Digite a base: ";
    cin >> base;
    
    cout << "Digite o expoente: ";
    cin >> expoente;
    
    cout << "O valor é " << potencia(base, expoente) << ".";

    return 0;
}