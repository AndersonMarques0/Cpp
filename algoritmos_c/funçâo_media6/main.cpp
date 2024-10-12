#include <iostream>
#include<iomanip>

using namespace std;

double media(double nota1, double nota2, double nota3, double nota4, double nota5, double nota6)
{
    double soma;
    soma = nota1+nota2+nota3+nota4+nota5+nota6;
    return soma/6;
}

int main()
{
    double n1,n2,n3,n4,n5,n6;
    cout<<"Este programa calcula a média de 6 notas.\n";
    cout<<"Digite o valor das seis notas: ";
    cin>>n1>>n2>>n3>>n4>>n5>>n6;
    media(n1,n2,n3,n4,n5,n6);
    if(media(n1,n2,n3,n4,n5,n6)>=0 && media(n1,n2,n3,n4,n5,n6)<=5)
    {
        cout<<"A média é "<<fixed<<setprecision(1)<<media(n1,n2,n3,n4,n5,n6)<<endl;
        cout<<"Reprovado.";
    }else if(media(n1,n2,n3,n4,n5,n6)>5 && media(n1,n2,n3,n4,n5,n6)<=7)
    {
        cout<<"A média é "<<fixed<<setprecision(1)<<media(n1,n2,n3,n4,n5,n6)<<endl;
        cout<<"Recuperação.";
    }else if(media(n1,n2,n3,n4,n5,n6)>7 && media(n1,n2,n3,n4,n5,n6)<=9)
    {
        cout<<"A média é "<<fixed<<setprecision(1)<<media(n1,n2,n3,n4,n5,n6)<<endl;
        cout<<"Satisfatorio.";
    }else if(media(n1,n2,n3,n4,n5,n6)>9 && media(n1,n2,n3,n4,n5,n6)<=10)
    {
        cout<<"A média é "<<fixed<<setprecision(1)<<media(n1,n2,n3,n4,n5,n6)<<endl;
        cout<<"Ótimo.";
    }
    
    
    return 0;
}