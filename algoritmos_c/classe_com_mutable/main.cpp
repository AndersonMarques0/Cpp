#include <iostream>
#include <cstring>
using namespace std;

class Cliente
{
    private:
        string nome, CPF;
        mutable int idade;
    
    public:
        Cliente( string n, string cpf, int i)
        {
            nome = n;
            CPF = cpf;
            idade = i;
        }
        
        int printIdade() const
        {
            return idade;
        }
        
        void idadeMudou(int i) const
        {
            idade = i;
        }
};

int main()
{
    const Cliente A("José da Silva","11111111111",76);
    
    cout << A.printIdade();
    
    A.idadeMudou(77);
    
    cout << endl << A.printIdade();

    return 0;
}