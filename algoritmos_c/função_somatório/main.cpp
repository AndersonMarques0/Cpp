#include <iostream>

using namespace std;

double somatorio(double n)
{
    int i=0;
    double somatorio=0;
    
    while(i<=n)
    {
        somatorio = somatorio + i;
        i++;
    }
    
    return somatorio;
}

int main()
{
    double num;
    
    cout<<"Este programa retorna o valor do somatório do número digitado\n";
    cout<<"Digite um número: ";
    cin>>num;
    somatorio(num);
    cout<<"Este é o valor do somatório: "<<somatorio(num);

    return 0;
}