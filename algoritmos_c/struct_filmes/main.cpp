#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    struct filmes{
        int codigo;
        string titulo, genero, categoria;
        double valor;
    }filme[3];
    
    cout<<"Cadastro de filmes.\n";
    
    for(int i=0;i<3;i++)
    {
        cout<<"Digite o código do filme: ";
        cin>>filme[i].codigo;
        cout<<"Digite o título do filme: ";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin,filme[i].titulo);
        cout<<"Digite o gênero: ";
        getline(cin,filme[i].genero);
        cout<<"Digite a categoria: ";
        getline(cin,filme[i].categoria);
        cout<<"Digite o valor: ";
        cin>>filme[i].valor;
    }
    
    cout<<"\nPreço total dos filmes alugados.\n";
    
    int codigo, qtdd, posicao,i=0;
    char res;
    double valor, total=0;
    
    do{
        cout<<"Digite o código do filme alugado: ";
        cin>>codigo;
        cout<<"Digite a quantidade de filmes alugados: ";
        cin>>qtdd;
        posicao = codigo - 1;
        valor = filme[posicao].valor * qtdd;
        total = total + valor;
        cout<<"Alugou outro filme? ";
        cin>>res;
        if(res=='s'|| res=='S' || res=='sim' || res=='Sim' || 'SIM')
        {
            i++;
        }else
        {
            break;
        }
    }while(i<3);
    
    cout<<"\nValor total dos filmes alugados: "<<total;

    return 0;
}
