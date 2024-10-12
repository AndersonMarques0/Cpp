#include <iostream>

using namespace std;

double prestacao(double valor, double taxa, int tempo)
{
    double resultado;
    
    resultado = valor+(valor*(taxa/100)*tempo);
    return resultado;
}

int main()
{
    int tempo;
    double valor, taxa;
    
    cout<<"Este programa calcula o valor da sua prestação!\n";
    cout<<"Digite o valor: ";
    cin>>valor;
    cout<<"Digite a taxa ao ano: ";
    cin>>taxa;
    cout<<"Digite o tempo em anos: ";
    cin>>tempo;
    prestacao(valor, taxa, tempo);
    cout<<"Este é o valor da sua prestação: "<<prestacao(valor,taxa,tempo);

    return 0;
}