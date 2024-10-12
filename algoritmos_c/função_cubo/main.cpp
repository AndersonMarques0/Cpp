#include <iostream>

using namespace std;

int cubo(int p)
{
    return p*p*p;
}

int main()
{
    int num;
    cout<<"Digite um número inteiro: ";
    cin>>num;
    cout<<cubo(num);
    /*
    resultado = cubo(num);
    cout<<resultado;
    */

    return 0;
}