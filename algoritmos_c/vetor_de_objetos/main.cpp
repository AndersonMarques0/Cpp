#include <iostream>

using namespace std;

const int MAX_PRODUTOS = 3;

class Produto
{
    private:
        string nome;
        float preco;
    
    public:
        Produto() : nome(""), preco(0.0) {} // construtor padrao
        Produto(string nome, float preco) : nome(nome), preco(preco) {}
    
        string getNome() const {
            return nome;
        }
    
        float getPreco() const {
            return preco;
        }
};

int main() {
    // Criando um array de objetos da classe Produto
    Produto listaProdutos[MAX_PRODUTOS];

    // Adicionando alguns produtos ao array
    listaProdutos[0] = Produto("Camiseta", 20.0);
    listaProdutos[1] = Produto("Calça Jeans", 50.0);
    listaProdutos[2] = Produto("Tênis", 30.0);

    // Exibindo os produtos
    cout << "Lista de Produtos:\n";
    for (int i = 0; i < MAX_PRODUTOS; ++i) {
        cout << listaProdutos[i].getNome() << ", Preço: R$ " << listaProdutos[i].getPreco() << endl;
    }

    return 0;
}
