#include <iostream>

using namespace std;

void maior(double a, double b, double c)
{
    if(a>b && a>c)
    {
        cout<<"O maior número digitado é "<<a<<".";
    }else if(b>a && b>c)
    {
        cout<<"O maior número digitado é "<<b<<".";
    }else if(c>a && c>b)
    {
        cout<<"O maior número digitado é "<<c<<".";
    }
}

void menor(double a, double b, double c)
{
    if(a<b && a<c)
    {
        cout<<"O menor número digitado é "<<a<<".";
    }else if(b<a && b<c)
    {
        cout<<"O menor número digitado é "<<b<<".";
    }else if(c<a && c<b)
    {
        cout<<"O menor número digitado é "<<c<<".";
    }
}

int main()
{
    int a, b, c;
    cout<<"Este programa mostra o maior e o menor número digitado.\n";
    cout<<"Digite três números.\n";
    cin>>a>>b>>c;
    maior(a,b,c);
    cout<<endl;
    menor(a,b,c);

    return 0;
}