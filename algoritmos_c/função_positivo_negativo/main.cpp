#include <iostream>

using namespace std;

char verificar(int n)
{
    if(n>0)
    {
        return 'p';
    }else
    {
        return 'n';
    }
}

int main()
{
    int num;
    cout<<"Digite um número: ";
    cin>>num;
    verificar(num);
    cout<<"Este é o resultado: "<<verificar(num);

    return 0;
}