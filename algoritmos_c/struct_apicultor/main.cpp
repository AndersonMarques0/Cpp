#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    struct colmeias{
        int codigo, num_abelhas, qualificacao;
        string regiao, estado;
    }colmeia[3];
    
    cout<<"Banco de dados de apicultores.\n";
    
    for(int i=0;i<3;i++)
    {
        cout<<"Digite o código da colmeia: ";
        cin>>colmeia[i].codigo;
        cout<<"Digite a região: ";
        cin>>colmeia[i].regiao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Digite o estado: ";
        getline(cin,colmeia[i].estado);
        cout<<"Digite a qualificação: \n1-Forte.\n2-Médio.\n3-Fraco.\n";
        cin>>colmeia[i].qualificacao;
    }
    
    int qualificacao;
    
    cout<<"\nProcure a qualificação: \n1-Forte.\n2-Médio.\n3-Fraco.\n";
    cin>>qualificacao;
    
    for(int i=0;i<3;i++)
    {
        if(colmeia[i].qualificacao==qualificacao)
        {
            cout<<endl;
            cout<<"Código: "<<colmeia[i].codigo<<endl;
            cout<<"Região: "<<colmeia[i].regiao<<endl;
            cout<<"Estado: "<<colmeia[i].estado<<endl;
        }
    }

    return 0;
}
