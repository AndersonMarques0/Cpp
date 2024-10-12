#include <iostream>
#include <iomanip>
using namespace std;

class Venda
{
    private:
        int npecas;
        float preco;
    public:
        Venda() {}
        Venda(int np, float p)
        { npecas = np; preco = p;}
        void getVenda();
        void printVenda() const;
        void add_venda(Venda v1, Venda v2);
};

void Venda::getVenda()
{
    cout << "Insira o número de peças: "; cin >> npecas;
    cout << "Insira o preço: "; cin >> preco;
}

void Venda::printVenda() const
{
    cout << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << setprecision(2)
         << setw(10) << npecas;
    cout << setw(10) << preco << endl;
}

void Venda::add_venda(Venda v1, Venda v2)
{
    npecas = v1.npecas + v2.npecas;
    preco = v1.preco + v2.preco;
}

int main()
{
    Venda A(58, 1200.58), B, Total;
    
    B.getVenda();
    Total.add_venda(A, B);
    
    cout << endl;
    cout << "Venda A........."; A.printVenda();
    cout << "Venda B........."; B.printVenda();
    cout << "Totais.........."; Total.printVenda();

    return 0;
}