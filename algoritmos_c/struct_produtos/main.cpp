#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    struct produtos{
        int codigo, estoque, qtddm;
        double preco;
        string descricao;
    }produto[3];
    
    cout<<"Cadastro de produtos.\n";
    
    
    for(int i=0;i<3;i++)
    {
        cout<<"Digite o código do produto: ";
        cin>>produto[i].codigo;
        cout<<"Digite a descrição do produto: ";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin,produto[i].descricao);
        cout<<"Digite a quantidade em estoque: ";
        cin>>produto[i].estoque;
        cout<<"Digite a quantidade mínima de estoque: ";
        cin>>produto[i].qtddm;
        cout<<"Digite o preço do produto: ";
        cin>>produto[i].preco;
        
    }
    
    cout<<"\nLista de produtos com estoque baixo.\n";
    
    for(int i=0;i<3;i++)
    {
        if(produto[i].estoque<produto[i].qtddm)
        {
            cout<<"\nDescrição:         "<<produto[i].descricao<<endl;
            cout<<"Estoque:           "<<produto[i].estoque<<endl;
            cout<<"Quantidade Mínima: "<<produto[i].qtddm<<endl;
        }
    }

    return 0;
}