#include <iostream>

using namespace std;

struct Venda{
    int pecas;
    float preco;
};

void listavendas( Venda C, Venda D);
Venda novavenda(void);

int main()
{
    Venda A, B;
    
    A = novavenda();
    B = novavenda();
    listavendas(A, B);
    cout << endl;

    return 0;
}

void listavendas(Venda C,Venda D)
{
    
    cout << "\n\n" << "Venda Total" << '\n' << "============";
    cout << '\n' << "Total de pecas: " << (C.pecas + D.pecas);
    cout << '\n' << "Preço total: " << (C.preco + D.preco);
    
}

Venda novavenda()
{
    Venda X;
    cout << '\n' << "Nova Venda" << '\n' << "=============" << endl;
    cout << "Insira o número de peças: ";
    cin >> X.pecas;
    cout << "Insira o preço: ";
    cin >> X.preco;
    return X;
}