#include <iostream>

using namespace std;

int main()
{
    string sexo;
    int idade, i, somam, somaf;
    for(i=1;i<=15;i++){
        cout<<"Digite o seu sexo: ";
        cin>>sexo;
        cout<<"Digite a sua idade: ";
        cin>>idade;
        if(sexo=="m" && idade>17){
            somam = somam + 1;
        }else if(sexo=="f" && idade>17){
            somaf = somaf + 1;
        }
    }
    cout<<"Homens maiores de 18 anos: "<<somam<<".\n";
    cout<<"Mulheres maiores de 18 anos: "<<somaf<<".\n";
    return 0;
}
