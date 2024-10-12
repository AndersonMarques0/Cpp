/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    string mercadoria, tipo, A, B;
    double preco, desconto;
    cout << "Digite o nome da mercadoria: ";
    cin >> mercadoria;
    cout << "Digite o tipo da mercadoria A ou B: ";
    cin >> tipo;
    cout << "Digite o valor da mercadoria: ";
    cin >> preco;
    
    if(tipo=="B" && preco<50){
        desconto = preco - (preco * 0.12);
        cout << "A mercadoria " << mercadoria << " com o preço " << preco << " sairá pelo valor R$ " << desconto << ".";
    }else if(tipo=="B" && preco>=50){
        desconto = preco - (preco * 0.1);
        cout << "A mercadoria " << mercadoria << " com o preço " << preco << " sairá pelo valor R$ " << desconto << ".";
    }else if(tipo=="A" && preco<100){
        desconto = preco - (preco * 0.08);
        cout << "A mercadoria " << mercadoria << " com o preço " << preco << " sairá pelo valor R$ " << desconto << ".";
    }else if(tipo=="A" && preco>=100){
        desconto = preco - (preco * 0.05);
        cout << "A mercadoria " << mercadoria << " com o preço " << preco << " sairá pelo valor R$ " << desconto << ".";
    }
    
    
    return 0;
}