#include <iostream>

using namespace std;

int main()
{
    double soma;
    
    struct mercadoria
    {
        string nome;
        double pu, preco_total;
        int qtdd;
        
        double valordavenda(double pu, int preco_total)
        {
            return pu*preco_total;
        }
        
    }venda[5];
    
    
    for(int i=0;i<5;i++)
    {
        cout<<"Digite o nome da mercadoria: ";
        cin>>venda[i].nome;
        cout<<"Digite o preço unitário da mercadoria: ";
        cin>>venda[i].pu;
        cout<<"Digite a quantidade vendida: ";
        cin>>venda[i].qtdd;
        venda[i].valordavenda(venda[i].pu,venda[i].qtdd);
        
        soma += venda[i].valordavenda(venda[i].pu,venda[i].qtdd);
        
    }
    
    cout<<"\nO preço final da compra é "<<soma<<".";
    
    

    return 0;
}