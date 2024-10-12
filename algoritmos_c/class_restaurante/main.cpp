#include <iostream>
#define max 3
using namespace std;

class Restaurante
{
    private:
        string nome, endereco, comida;
        double preco;
    public:
        Restaurante() : nome(""), endereco(""), comida(""), preco(0) {}
        Restaurante(string n, string e, string c, double p) : nome(n), endereco(e), comida(c),
        preco(p) {}
        
        void init(string n, string e, string c, double p)
        {
            nome = n;
            endereco = e;
            comida = c;
            preco = p;
        }
        
        void print()
        {
            cout << "Nome do restaurante: " << nome << endl;
            cout << "Endereço: " << endereco << endl;
            cout << "Comida: " << comida << endl;
            cout << "Preco: " << preco << endl;
        }
        
        string prato() const
        {
            return comida;
        }
};

int main()
{
    Restaurante lista[max];
    string nome, endereco, comida;
    double preco;
    
    for(int i=0; i < max; i++)
    {
        cout << "Digite o nome do restaurante: "; cin >> nome;
        cout << "Digite o endereço: "; cin >> endereco;
        cout << "Digite a comida: "; cin >> comida;
        cout << "Digite o preço: "; cin >> preco;
        lista[i].init(nome, endereco, comida, preco);
    }
    
    cout << "Digite a comida que procura: "; cin >> comida;
    
    for(int i=0; i < max; i++)
    {
        if(lista[i].prato() == comida)
        {
            cout << endl;
            lista[i].print();
        }
    }

    return 0;
}