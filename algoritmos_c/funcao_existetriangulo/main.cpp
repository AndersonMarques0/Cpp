#include <iostream>

using namespace std;

void existeTriangulo(int a, int b, int c)
{
    if(a<b+c && b<a+c && c<a+b)
    {
        cout<<"O triangulo existe.\n";
    }else
    {
        cout<<"O triangulo nao existe.\n";
    }
}

int main()
{
    int a, b, c;
    
    cout<<"Este programa se o triangulo existe.\n";
    cout<<"Digite os valores dos lados dos triangulos.\n";
    cin>>a>>b>>c;
    existeTriangulo(a,b,c);

    return 0;
}