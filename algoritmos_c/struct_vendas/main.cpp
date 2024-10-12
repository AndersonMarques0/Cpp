#include <iostream>

using namespace std;

struct Venda{
    int pecas;
    float preco;
};

void listavenda( Venda D, Venda C);

int main()
{
    Venda A, B;
    
    cout << "Venda A" << '\n' << "=======" << endl;
    cout << "Insira o número de peças: ";
    cin >> A.pecas;
    cout << "Insira o preço: ";
    cin >> A.preco;
    
    cout << '\n' << "Venda B" << '\n' << "=======" << endl;
    cout << "Insira o número de peças: ";
    cin >> B.pecas;
    cout << "Insira o preço: ";
    cin >> B.preco;
    
    listavenda(A, B);
    
    cout << endl;
    

    return 0;
}

void listavenda (Venda D, Venda C){
    
    cout << "\n\n" << "Venda Total" << "\n" << "============";
    cout << "\n" << "Total de peças: " << (C.pecas + D.pecas);
    cout << "\n" << "Preço total: " << (C.preco + D.preco); 
    
}