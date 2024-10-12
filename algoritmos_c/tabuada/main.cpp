#include <iostream>

using namespace std;

int main()
{
    int num, tabuada, i;
    cout<<"Digite um número inteiro.\n";
    cin>>num;
    for(i=1;i<=10;i++){
        tabuada = num * i;
        cout<<num<<" x "<<i<<" = "<<tabuada<<".\n";
    }

    return 0;
}
