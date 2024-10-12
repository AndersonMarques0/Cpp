#include <bits/stdc++.h>

using namespace std;

int main()
{
    int idade, media, soma1, i, anterior;
    double peso, altura, ptg, soma2;
    
    cout<<"Este programa calcula a média das idades.\n";
    cout<<"Número de pessoas com peso maior que 90Kg e menos de 1.50m de altura.\n";
    cout<<"Calcula a porcentagem de pessoas entre 10 e 30 anos maiores que 1.90m de altura.\n\n";
    
    for(i=1;i<=10;i++)
    {
        cout<<"Digite sua idade: ";
        cin>>idade;
        cout<<"Digite o seu peso em Kg: ";
        cin>>peso;
        cout<<"Digite sua altura em metros: ";
        cin>>altura;
        
        if(peso>90 && altura<1.50){
            soma1 = soma1 + 1;
        }
        
        if(idade>9 && idade<31 && altura>1.90){
            soma2 = soma2 + 1;
        }
        
        idade = idade + anterior;
        anterior = idade;
    }
    
    ptg = (soma2/10) * 100;
    media = idade/10;
    
    cout<<"Média das idades é "<<media<<".\n";
    cout<<"Número de pessoas com peso maior que 90Kg e menos de 1.50m de altura é "<<soma1<<".\n";
    cout<<fixed<<setprecision(2)<<"Porcentagem de pessoas entre 10 e 30 anos maiores que 1.90m de altura é "<<ptg<<"%.\n";

    return 0;
}

