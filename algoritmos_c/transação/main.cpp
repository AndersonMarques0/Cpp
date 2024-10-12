#include <bits/stdc++.h>

using namespace std;

int main()
{
    string tipo;
    int i;
    double valor, anterior,anteriorp, somav, somap, somat;
    
    cout<<"Este programa calcula a soma das compras à vista e à prazo e total de tudo.\n";
    for(i=1;i<=5;i++){
        cout<<"Digite V para compra à vista ou P para compra à prazo.\n";
        cin>>tipo;
        cout<<"Digite o valor da compra.\n";
        cin>>valor;
        
        if(tipo=="V"){
            somav = valor = valor + anterior;
            anterior = valor;
        }else if(tipo=="P"){
            somap = valor = valor + anteriorp;
            anteriorp = valor;
        }
    }
    somat = somav + somap;
    cout<<fixed<<setprecision(2)<<"Valor total das transações à vista: R$ "<<somav<<".\n";
    cout<<fixed<<setprecision(2)<<"Valor total das transações à prazo: R$ "<<somap<<".\n";
    cout<<fixed<<setprecision(2)<<"Valor total das transações: R$ "<<somat<<".\n";

    return 0;
}
