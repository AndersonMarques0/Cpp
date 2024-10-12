#include <iostream>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

int main()
{
    struct aeroporto{
        int codigo, passageiros;
        string origem, destino, horario;
        double valor;
    }voo[3];
    
    cout<<"Banco de dados de vôos.\n";
    
    for(int i=0;i<3;i++)
    {
        cout<<"Digite o código do voo: ";
        cin>>voo[i].codigo;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Digite a origem do voo: ";
        getline(cin,voo[i].origem);
        cout<<"Digite o destino do voo: ";
        getline(cin,voo[i].destino);
        cout<<"Digite o horário de partida em formato HH:MM.\n";
        getline(cin,voo[i].horario);
        tm horario = {0};
        strptime(voo[i].horario.c_str(),"%H:%M",&horario);
        cout<<"Digite o valor da passagem: ";
        cin>>voo[i].valor;
        cout<<"Digite a quantidade de passageiros: ";
        cin>>voo[i].passageiros;
        
        
    }
    
    string origem;
    
    cout<<"\nDigite a origem do voo.\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,origem);
    
    for(int i=0;i<3;i++)
    {
        if(voo[i].origem==origem)
        {
            cout<<endl<<"Código do voo: "<<voo[i].codigo;
            cout<<"Origem do voo: "<<voo[i].origem;
            cout<<"Destino do voo: "<<voo[i].destino;
            cout<<"Horário do voo: "<<voo[i].horario;
            cout<<"Valor da passagem: "<<voo[i].valor;
            cout<<"Quantidade de passageiros: "<<voo[i].passageiros;
        }
    }

    return 0;
}