#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    struct municipio{
        int populacao;
        string estado, nome;
    }geo[3];
    
    cout<<"Banco de dados de municípios.\n";
    
    for(int i=0;i<3;i++)
    {
        
        cout<<"Digite o estado: ";
        getline(cin,geo[i].estado);
        cout<<"Digite o nome do município: ";
        getline(cin,geo[i].nome);
        cout<<"Digite a população do município: ";
        cin>>geo[i].populacao;
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    }

    cout<<"Mostra todos os munícipios do estado do Paraná cadastrados.\n";
    
    for(int i=0;i<3;i++)
    {
        if(geo[i].estado=="Paraná")
        {
            cout<<endl<<"Estado: "<<geo[i].estado<<endl;
            cout<<"Município: "<<geo[i].nome<<endl;
            cout<<"População: "<<geo[i].populacao<<endl;
        }
    }
    
    return 0;
}