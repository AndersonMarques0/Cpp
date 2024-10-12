#include <iostream>

using namespace std;

int main()
{
    int prato, sobremesa, bebida, calorias;
    
    cout<<"Escolha um prato de 1 a 4.\n1 - Vegetariano.\n2 - Peixe.\n3 - Frango.\n4 - Carne.\n";
    cin>>prato;
    cout<<"Escolha uma sobremesa de 1 a 4.\n1 - Abacaxi.\n2 - Sorvete diet.\n3 - Mouse diet.\n4 - Mouse de chocolate.\n";
    cin>>sobremesa;
    cout<<"Escolha uma bebida de 1 a 4.\n1 - Chá.\n2 - Suco de laranja.\n3 - Suco de melão.\n4 - Refrigerante diet.\n";
    cin>>bebida;
    
    switch(prato){
        case 1:
            prato = 180;
        break;
        case 2:
            prato = 230;
        break;
        case 3:
            prato = 250;
        break;
        case 4:
            prato = 350;
        break;
    }
    
    switch(sobremesa){
        case 1:
            sobremesa = 75;
        break;
        case 2:
            sobremesa = 110;
        break;
        case 3:
            sobremesa = 170;
        break;
        case 4:
            sobremesa = 200;
        break;
    }
    
    switch(bebida){
        case 1:
            bebida = 20;
        break;
        case 2:
            bebida = 70;
        break;
        case 3:
            bebida = 100;
        break;
        case 4:
            bebida = 65;
        break;
    }
    
    calorias = prato + sobremesa + bebida;
    
    cout<<"O total de calorias é "<<calorias<<"cal.";
    
    

    return 0;
}