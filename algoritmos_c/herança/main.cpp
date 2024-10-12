#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Cadastro
{
    private:
        char nome[30], fone[20];
    public:
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
            cout << "...Imóvel: " << endl;
            Imovel::print();
            Tipo::print();
            cout << '\t' << "Valor US$: " << valor;
        }
};

class Aluguel : private Cadastro, Imovel, Tipo
{
    private:
        float aluguelMensal;
        int prazo;
        Cadastro proprietario;
    public:
        void get()
        {
            cout << '\n' << "...Proprietário: ";
            proprietario.get();
            cout << '\n' << "...Inquilino: ";
            Cadastro::get();
            cout << '\n' << "...Imóvel: ";
            Imovel::get();
            Tipo::get();
            cout << '\t' << "Aluguel: "; cin >> aluguelMensal;
            cout << '\t' << "Prazo do contrato: "; cin >> prazo;
        }
        
        void print()
        {
            cout << '\n' << "...Proprietário: " << endl;
            Cadastro::print();
            cout << "...Imóvel: " << endl;
            Imovel::print();
            Tipo::print();
            cout << "\n\t" << "Aluguel: " << aluguelMensal << endl;
            cout << "\n" << "Prazo do contrato: " << prazo << endl;
            
        }

};

int main()
{
    Venda V;
    Aluguel A;
    
    cout << '\n' << "Digite os dados do imóvel. Venda." << endl;
    V.get();
    
    cout << '\n' << "Digite os dados do imóvel. Aluguel." << endl;
    A.get();
    
    cout << "\n\n" << "*Imóvel para venda." << endl;
    V.print();
    
    cout << "\n" << "*Imóvel para aluguel." << endl;
    A.print();

    return 0;
}