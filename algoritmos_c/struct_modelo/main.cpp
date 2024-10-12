#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    
    struct modelos{
        int num_inscricao;
        string nome, naturalidade, estado;
        double altura, peso;
    }modelo[30];
    
    cout<<"Cadastro de modelos.\n";
    
    for(int i=0;i<30;i++)
    {
        cout<<"Digite o número de inscrição: ";
        cin>>modelo[i].num_inscricao;
        cin.ignore();
        cout<<"Digite o nome: ";
        getline(cin,modelo[i].nome);
        cout<<"Digite a naturalidade: ";
        getline(cin,modelo[i].naturalidade);
        cout<<"Digite o estado de origem: ";
        getline(cin, modelo[i].estado);
        cout<<"Digite o peso: ";
        cin>>modelo[i].peso;
        cout<<"Digite a altura: ";
        cin>>modelo[i].altura;
    }
    
    cout<<"\nNomes de modelos com mais de 1.84 e que são de São Paulo.\n";
    
    for(int i=0;i<30;i++)
    {
        string estado_minusculo = modelo[i].estado;
        transform(estado_minusculo.begin(), estado_minusculo.end(), estado_minusculo.begin(), [](unsigned char c){ return tolower(c); });
        
        if(modelo[i].altura>=1.85 && estado_minusculo=="sao paulo")
        {
            
            cout<<modelo[i].nome<<endl;
            
        }
    }
    
    return 0;
}

