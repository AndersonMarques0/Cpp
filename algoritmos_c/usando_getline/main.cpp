#include <iostream>


using namespace std;

int main()
{
    string nome;
    
    cout << "Digite o seu nome: ";
    getline(cin, nome);
    
    cout << "\n" << "Seu nome é " << nome;

    return 0;
}