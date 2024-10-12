#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Cadastro
{
    private:
        char nome[30], fone[20];
    public:
        Cadastro()
        {
            nome[0]=fone[0]='\0';
        }
        
        Cadastro(char n[], char f[])
        {
            strcpy(nome, n);
            strcpy(fone, f);
        }
        
        void get()
        {
            cout << '\t' << "Nome: "; cin.getline(nome,sizeof(nome));
            cout << '\t' << "Telefone: "; cin.getline(fone,sizeof(fone));
        }
        
        void print()
        {
            cout << "\n\t" << "Nome: " << nome;
            cout << "\n\t" << "Telefone: " << fone;
        }
};

class Imovel
{
    private:
        char endereco[30], bairro[20];
        float areaUtil, areaTotal;
        int quartos;
    public:
        Imovel() : areaUtil(0), areaTotal(0), quartos(0)
        {
            endereco[0]=bairro[0]='\0';
        }
        
        Imovel(char e[], char b[], float au, float at, int q)
        {
            strcpy(endereco, e);
            strcpy(bairro, b);
            areaUtil = au;
            areaTotal = at;
            quartos = q;
        }
        
        void get()
        {
            cout << '\t' << "Endereço: "; cin.getline(endereco, sizeof(endereco));
            cout << '\t' << "Bairro: "; cin.getline(bairro, sizeof(bairro));
            cout << '\t' << "Área útil: "; cin >> areaUtil;
            cout << '\t' << "Área total: "; cin >> areaTotal;
            cout << '\t' << "Quartos: "; cin >> quartos;
        }
        
        void print()
        {
            cout << "\n\t" << "Endereço: " << endereco;
            cout << "\n\t" << "Bairro: " << bairro;
            cout << "\n\t" << "Área útil: " << areaUtil;
            cout << "\n\t" << "Área total: " << areaTotal;
            cout << "\n\t" << "Quartos: " << quartos;
        }
};

class Tipo
{
    private:
        char tipoImovel[20];
    public:
        Tipo()
        {
            tipoImovel[0]='\0';
        }
        
        Tipo(char t[])
        {
            strcpy(tipoImovel, t);
        }
        
        void get()
        {
            cout << '\t' << "Tipo: "; cin.getline(tipoImovel, sizeof(tipoImovel));
        }
        
        void print()
        {
            cout << '\t' << "Tipo: " << tipoImovel << endl;
        }
};

class Venda : private Cadastro, Imovel, Tipo
{
    private:
        float valor;
    public:
        Venda() : Cadastro(), Imovel(), Tipo(), valor(0.0) {}
        
        Venda(char n[], char f[], char e[], char b[], float au, float at, int q, char t[], float v) 
            : Cadastro(n, f), Imovel(e, b, au, at, q), Tipo(t), valor(v) {}
        
        void get()
        {
            cout << '\n' << "...Proprietário: " << endl;
            Cadastro::get();
            cout << '\n' << "...Imóvel: " << endl;
            Imovel::get();
            Tipo::get();
            cout << '\t' << "Valor US$: "; cin >> valor;
            
        }
        
        void print()
        {
            cout << '\n' << "...Proprietário: " << endl;
            Cadastro::print();
            cout << "\n\n" <<"...Imóvel: " << endl;
            Imovel::print();
            Tipo::print();
            cout << '\t' << "Valor US$: " << valor;
        }
};



int main()
{
    Venda V("Andre Serafin", "33-3333", "Rua rochar 83", "Bela Vista", 50.0, 75.0, 2, "Residencial", 2000.0);
    
    
    cout << "\n\n Imóvel para Venda" << endl;
    V.print();
    

    return 0;
}
