#include <iostream>
#include <iomanip>
using namespace std;

class Venda
{
    private:
        int npecas;
        float preco;
    public:
        Venda() {}  // construtor padrão
        Venda(int np, float p) // construtor com argumentos
        { npecas = np; preco = p;}
        void getVenda();
        void printVenda() const;
        Venda operator+(Venda& x);
};

void Venda::getVenda()
{
    cout << "Insira o número de peças: "; cin >> npecas;
    cout << "Insira o preço: "; cin >> preco;
}

void Venda::printVenda() const
{
    cout << setiosflags(ios::fixed)  // nao notação científica
         << setiosflags(ios::showpoint) // ponto decimal
         << setprecision(2) // duas casas
         << setw(10) << npecas;
    cout << setw(10) << preco << endl;
}

Venda Venda::operator+(Venda& x)
{
    Venda temp;
    temp.npecas = npecas + x.npecas;
    temp.preco = preco + x.preco;
    return temp;
}

int main()
{
    Venda A(58, 1200.58), B, C(30,6000.31), Total, subTotal;
    
    B.getVenda();
    
    subTotal = A + B;
    Total = A + B + C;
    
    cout << endl;
    cout << "Venda A........."; A.printVenda();
    cout << "Venda B........."; B.printVenda();
    cout << "Subtotal........"; subTotal.printVenda();
    cout << "Totais.........."; Total.printVenda();

    return 0;
}