#include <iostream>

using namespace std;

int main()
{
    int num, i, par, impar;
    for(i=1;i<=10;i++){
        cout<<"Digite um número inteiro: ";
        cin>>num;
        if(num%2==0){
            par = par + 1;
        }else{
            impar = impar + 1;
        }
    }
    cout<<"Quantidade de números pares: "<<par<<".\n";
    cout<<"Quantidade de números ímpares: "<<impar<<".\n";

    return 0;
}
