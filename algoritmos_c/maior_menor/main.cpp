#include <iostream>

using namespace std;

int main()
{
    int num, maior, menor, i;
    for(i=1;i<=5;i++){
        cout<<"Digite um número: ";
        cin>>num;
        if(num<menor){
            menor = num;
        }else if(num>maior){
            maior = num;
        }
    }
    cout<<"Este é o maior número: "<<maior<<".\n";
    cout<<"Este é o menor número: "<<menor<<".\n";

    return 0;
}
