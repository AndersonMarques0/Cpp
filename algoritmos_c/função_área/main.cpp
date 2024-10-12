#include <iostream>

using namespace std;

double quadrado(double valor)
{
    return valor*valor;
}

double retangulo(double valor)
{
    return valor*valor;
}

double circulo(double raio)
{
    double pi=3.14;
    
    return pi*(raio*raio);
}

int main()
{
    int num;
    cout<<"Digite o número corresponde ao tipo de cálculo: \n1-Área do quadrado\n2-Área do retângulo\n3-Área do círculo\nValor: ";
    cin>>num;
    if(num==1)
    {
        double valor;
        cout<<"Digite o valor do lado do quadrado em metros: ";
        cin>>valor;
        quadrado(valor);
        cout<<"Este é o resultado: "<<quadrado(valor);
        
    }
    
    if(num==2)
    {
        double valor;
        cout<<"Digite o valor do lado do retângulo em metros: ";
        cin>>valor;
        retangulo(valor);
        cout<<"Este é o resultado: "<<retangulo(valor);
        
    }
    
    if(num==3)
    {
        double valor;
        cout<<"Digite o valor do raio do círculo em metros: ";
        cin>>valor;
        circulo(valor);
        cout<<"Este é o resultado: "<<circulo(valor);
        
    }
    

    return 0;
}