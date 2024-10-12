#include <iostream>

using namespace std;

int main()
{
    int cont, num_item, qtdd;
    double preco, total, totalgeral=0;
    
    do{
        cout<<"Digite o número do item: ";
        cin>>num_item;
        cout<<"Digite o preço unitário do item: ";
        cin>>preco;
        cout<<"Digite a quantidade de itens: ";
        cin>>qtdd;
        
        total = preco*qtdd;
        totalgeral = totalgeral + total;
        
    }while(qtdd>0);
    
    cout<<"A soma total das compras é "<<totalgeral<<".";

    return 0;
}
