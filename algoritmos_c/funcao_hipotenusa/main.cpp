#include <iostream>

using namespace std;

int hipotenusa(int a, int b)
    {
        int h;
        h = (a*a) + (b*b);
        return h;
    }

int main()
{
    int oposto, adjacente;
    
    cout<<"Este programa calcula a hipotenusa do triangulo retangulo.\n";
    cout<<"Digite os valores do cateto oposto e o cateto adjacente: ";
    cin>>oposto;
    cin>>adjacente;
    hipotenusa(oposto, adjacente);
    cout<<hipotenusa(oposto, adjacente);

    return 0;
}
