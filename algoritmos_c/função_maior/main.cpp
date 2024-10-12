#include <iostream>

using namespace std;

int maior(int a, int b)
{
    if(a>b)
    {
        return  a;
    }
    else
    {
        return b;
    }
}

int main()
{
    
    int num1, num2;
    cout<<"Digite dois números: ";
    cin>>num1>>num2;
    maior(num1,num2);
    cout<<"Este é o maior número: "<<maior(num1,num2);
    
    return 0;
    
}